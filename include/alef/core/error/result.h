#ifndef ALEF_CORE_ERROR_RESULT_H
#define ALEF_CORE_ERROR_RESULT_H

#include <iostream>
#include <functional>
#include <type_traits>
#include <concepts>

namespace alef::error {

template<typename T>
struct ok_type {
    T value;

public:
    ok_type(const T& value) : value{value}
    {
    }

    ok_type(T&& value) : value{std::move(value)}
    {
    }
};

template<>
struct ok_type<void> { };

template<typename E>
struct err_type {
    E value;

public:
    err_type(const E& value) : value(value) { }
    err_type(E&& value) : value(std::move(value)) { }
};

template<typename T, typename CleanT = typename std::decay<T>::type>
ok_type<CleanT> ok(T&& value)
{
    return ok_type<CleanT>(std::forward<T>(value));
}

inline ok_type<void> ok()
{
    return {};
}

template<typename E, typename CleanE = typename std::decay<E>::type>
err_type<CleanE> err(E&& value)
{
    return err_type<CleanE>(std::forward<E>(value));
}

template<typename T, typename E> class result;

namespace __detail {

template<typename ...>
struct void_t {
    using type = void;
};

namespace impl {

template<typename Func> struct result_of;

template<typename Ret, typename Class, typename... Args>
struct result_of<Ret (Class::*)(Args...)> : public result_of<Ret (Args...)> { };

template<typename Ret, typename... Args>
struct result_of<Ret (Args...)> {
    using type = Ret;
};

} // namespace impl

template<typename Func>
struct result_of : public impl::result_of<decltype(&Func::operator())> { };

template<typename Ret, typename Class, typename... Args>
struct result_of<Ret(Class::*) (Args...) const> {
    using type = Ret;
};

template<typename Ret, typename... Args>
struct result_of<Ret(*)(Args...)> {
    using type = Ret;
};

template<typename R>
struct result_ok_type {
    using type = typename std::decay<R>::type;
};

template<typename T, typename E>
struct result_ok_type<result<T, E>> {
    using type = T;
};

template<typename R>
struct result_err_type {
    using type = R;
};

template<typename T, typename E>
struct result_err_type<result<T, E>> {
    using type = typename std::remove_reference<E>::type;
};

template<typename R>
struct is_result : public std::false_type { };

template<typename T, typename E>
struct is_result<result<T, E>> : public std::true_type { };

namespace ok {

namespace impl {

template<typename T> struct map_type;

template<typename Ret, typename Class, typename Arg>
struct map_type<Ret(Class::*)(Arg) const> : public map_type<Ret(Arg)> { };

template<typename Ret, typename Class, typename Arg>
struct map_type<Ret(Class::*)(Arg)> : public map_type<Ret(Arg)> { };

// General implementation.
template<typename Ret, typename Arg>
struct map_type<Ret(Arg)> {
    template<typename T, typename E, typename Func>
    requires (!is_result<Ret>::value) && (std::same_as<T, Arg> || std::convertible_to<T, Arg>)
    static result<Ret, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            auto res = func(result.storage().template get<T>());
            return ok_type<Ret>(std::move(res));
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// Specialization for callback returning void.
template<typename Arg>
struct map_type<void(Arg)> {
    template<typename T, typename E, typename Func>
    static result<void, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            func(result.storage().template get<T>());
            return ok_type<void>();
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// Specialization for a void result.
template<typename Ret>
struct map_type<Ret(void)> {
    template<std::same_as<void> T, typename E, typename Func>
    static result<Ret, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            auto ret = func();
            return ok_type<Ret>(std::move(ret));
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// Specialization for callback returning void on a void result.
template<>
struct map_type<void(void)> {
    template<std::same_as<void> T, typename E, typename Func>
    static result<void, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            func();
            return ok_type<void>();
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// General specialization for a callback returning a Result
template<typename U, typename E, typename Arg>
struct map_type<result<U, E>(Arg)> {
    template<typename T, typename Func>
    requires std::same_as<T, Arg> || std::convertible_to<T, Arg>
    static result<U, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            auto res = func(result.storage().template get<T>());
            return res;
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// Specialization for a void callback returning a result.
template<typename U, typename E>
struct map_type<result<U, E>(void)> {
    template<std::same_as<void> T, typename Func>
    static result<U, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            auto res = func();
            return res;
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

} // namespace impl

template<typename Func> struct map : public impl::map_type<decltype(&Func::operator())> { };

template<typename Ret, typename... Args>
struct map<Ret(*)(Args...)> : public impl::map_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct map<Ret(Class::*)(Args...)> : public impl::map_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct map<Ret(Class::*)(Args...) const> : public impl::map_type<Ret (Args...)> { };

template<typename Ret, typename... Args>
struct map<std::function<Ret(Args...)>> : public impl::map_type<Ret (Args...)> { };

} // namespace ok

namespace err {

namespace impl {

template<typename T>
struct map_type;

template<typename Ret, typename Class, typename Arg>
struct map_type<Ret(Class::*)(Arg) const> {
    template<typename T, typename E, typename Func>
    requires (!is_result<Ret>::value)
    static result<T, Ret> map(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func(result.storage().template get<E>());
            return err_type<Ret>(res);
        }
        return ok_type<T>(result.storage().template get<T>());
    }

    template<typename E, typename Func>
    requires (!is_result<Ret>::value)
    static result<void, Ret> map(const result<void, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func(result.storage().template get<E>());
            return err_type<Ret>(res);
        }
        return ok_type<void>();
    }
};

} // namespace impl

template<typename Func>
struct map : public impl::map_type<decltype(&Func::operator())> { };

} // namespace err;

namespace and_ns {

namespace impl {

template<typename Func> struct then_type;

template<typename Ret, typename... Args>
struct then_type<Ret(*)(Args...)> : public then_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct then_type<Ret(Class::*)(Args...)> : public then_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct then_type<Ret(Class::*)(Args...) const> : public then_type<Ret (Args...)> { };

template<std::same_as<void> Ret, typename Arg>
struct then_type<Ret(Arg)> {
    template<typename T, typename E, typename Func>
    static result<T, E> then(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            func(result.storage().template get<T>());
        }
        return result;
    }
};

template<std::same_as<void> Ret>
struct then_type<Ret (void)> {
    template<std::same_as<void> T, typename E, typename Func>
    static result<T, E> then(const result<T, E>& result, Func func)
    {
        if (result.is_ok())
            func();

        return result;
    }
};

} // namespace impl

template<typename Func>
struct then : public impl::then_type<decltype(&Func::operator())> { };

template<typename Ret, typename... Args>
struct then<Ret(*)(Args...)> : public impl::then_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct then<Ret(Class::*)(Args...)> : public impl::then_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct then<Ret(Class::*)(Args...) const> : public impl::then_type<Ret (Args...)> { };

} // namespace and_ns

namespace or_ns {

namespace impl {

template<typename Func> struct else_type;

template<typename Ret, typename... Args>
struct else_type<Ret(*)(Args...)> : public else_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct else_type<Ret(Class::*)(Args...)> : public else_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct else_type<Ret(Class::*)(Args...) const> : public else_type<Ret (Args...)> { };

template<typename T, typename F, typename Arg>
struct else_type<result<T, F>(Arg)> {
    template<typename E, typename Func>
    requires std::same_as<E, Arg> || std::convertible_to<E, Arg>
    static result<T, F> or_else(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func(result.storage().template get<E>());
            return res;
        }
        return ok_type<T>(result.storage().template get<T>());
    }

    template<typename E, typename Func>
    requires std::same_as<E, Arg> || std::convertible_to<E, Arg>
    static result<void, F> or_else(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func(result.storage().template get<E>());
            return res;
        }
        return ok_type<void>();
    }
};

template<std::same_as<void> T, typename F>
struct else_type<result<T, F> (void)> {
    template<typename E, typename Func>
    static result<T, F> or_else(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func();
            return res;
        }
        return ok_type<T>(result.storage().template get<T>());
    }

    template<typename E, typename Func>
    static result<void, F> or_else(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func();
            return res;
        }
        return ok_type<void>();
    }
};

} // namespace impl

template<typename Func>
struct else_t : public impl::else_type<decltype(&Func::operator())> { };

template<typename Ret, typename... Args>
struct else_t<Ret(*)(Args...)> : public impl::else_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct else_t<Ret(Class::*)(Args...)> : public impl::else_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct else_t<Ret(Class::*)(Args...) const> : public impl::else_type<Ret (Args...)> { };

} // namespace or

namespace other {

namespace impl {

template<typename Func> struct wise_type;

template<typename Ret, typename... Args>
struct wise_type<Ret(*)(Args...)> : public wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise_type<Ret(Class::*)(Args...)> : public wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise_type<Ret(Class::*)(Args...) const> : public wise_type<Ret (Args...)> { };

template<std::same_as<void> Ret, typename Arg>
struct wise_type<Ret(Arg)> {
    template<typename T, typename E, typename Func>
    requires std::same_as<E, Arg> || std::convertible_to<E, Arg>
    static result<T, E> otherwise(const result<T, E>& result, Func func)
    {
        if (result.is_err())
            func(result.storage().template get<E>());

        return result;
    }
};

} // namespace impl

template<typename Func>
struct wise : public impl::wise_type<decltype(&Func::operator())> { };

template<typename Ret, typename... Args>
struct wise<Ret(*)(Args...)> : public impl::wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise<Ret(Class::*)(Args...)> : public impl::wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise<Ret(Class::*)(Args...) const> : public impl::wise_type<Ret (Args...)> { };

} // namespace other

template<
    typename T,
    typename E,
    typename Func,
    typename Ret = result<
        typename __detail::result_ok_type<typename __detail::result_of<Func>::type>::type, E>>
Ret map(const result<T, E>& result, Func func)
{
    return ok::map<Func>::map(result, func);
}

template<
    typename T,
    typename E,
    typename Func,
    typename Ret = result<
        T,
        typename __detail::result_err_type<typename __detail::result_of<Func>::type>::type>>
Ret map_error(const result<T, E>& result, Func func)
{
    return err::map<Func>::map(result, func);
}

template<typename T, typename E, typename Func>
result<T, E> then(const result<T, E>& result, Func func)
{
    return and_ns::then<Func>::then(result, func);
}

template<typename T, typename E, typename Func>
result<T, E> otherwise(const result<T, E>& result, Func func)
{
    return other::wise<Func>::otherwise(result, func);
}

template<
    typename T,
    typename E,
    typename Func,
    typename Ret = result<
        T,
        typename __detail::result_err_type<typename __detail::result_of<Func>::type>::type>>
Ret or_else_t(const result<T, E>& result, Func func)
{
    return or_ns::else_t<Func>::or_else(result, func);
}

struct ok_tag { };
struct err_tag { };

template<typename T, typename E>
class storage {
public:
    static constexpr std::size_t size = (sizeof(T) > sizeof(E)) ? sizeof(T) : sizeof(E);
    static constexpr std::size_t align = (sizeof(T) > sizeof(E)) ? alignof(T) : alignof(E);

    using type = typename std::aligned_storage<size, align>::type;

private:
    type storage_;
    bool initialized_{};

public:
    storage() = default;

    void construct(ok_type<T> ok)
    {
        new (&storage_) T(ok.value);
        initialized_ = true;
    }

    void construct(err_type<E> err)
    {
        new (&storage_) E(err.value);
        initialized_ = true;
    }

    template<typename U>
    void raw_construct(U&& value)
    {
        using clean_u_type = typename std::decay<U>::type;

        new (&storage_) clean_u_type(std::forward<U>(value));
        initialized_ = true;
    }

    template<typename U>
    const U& get() const
    {
        return *reinterpret_cast<const U *>(&storage_);
    }

    template<typename U>
    U& get()
    {
        return *reinterpret_cast<U *>(&storage_);
    }

    void destroy(ok_tag)
    {
        if (initialized_) {
            get<T>().~T();
            initialized_ = false;
        }
    }

    void destroy(err_tag)
    {
        if (initialized_) {
            get<E>().~E();
            initialized_ = false;
        }
    }
};

template<typename E>
class storage<void, E> {
public:
    using type = typename std::aligned_storage<sizeof(E), alignof(E)>::type;

private:
    type storage_;
    bool initialized_;

public:
    void construct(ok_type<void>) { initialized_ = true; }

    void construct(err_type<E> err)
    {
        new (&storage_) E(err.value);
        initialized_ = true;
    }

    template<typename U>
    void raw_construct(U&& value)
    {
        using clean_u_type = typename std::decay<U>::type;

        new (&storage_) clean_u_type(std::forward<U>(value));
        initialized_ = true;
    }

    void destroy(ok_tag)
    {
        initialized_ = false;
    }

    void destroy(err_tag)
    {
        if (initialized_) {
            get<E>().~E();
            initialized_ = false;
        }
    }

    template<typename U>
    const U& get() const
    {
        return *reinterpret_cast<const U *>(&storage_);
    }

    template<typename U>
    U& get()
    {
        return *reinterpret_cast<U *>(&storage_);
    }
};

template<typename T, typename E>
struct constructor {
    static void move(storage<T, E>&& src, storage<T, E>& dst, ok_tag)
    {
        dst.raw_construct(std::move(src.template get<T>()));
        src.destroy(ok_tag());
    }

    static void copy(const storage<T, E>& src, storage<T, E>& dst, ok_tag)
    {
        dst.raw_construct(src.template get<T>());
    }

    static void move(storage<T, E>&& src, storage<T, E>& dst, err_tag)
    {
        dst.raw_construct(std::move(src.template get<E>()));
        src.destroy(err_tag());
    }

    static void copy(const storage<T, E>& src, storage<T, E>& dst, err_tag)
    {
        dst.raw_construct(src.template get<E>());
    }
};

template<typename E>
struct constructor<void, E> {
    static void move(storage<void, E>&&, storage<void, E>&, ok_tag)
    {
    }

    static void copy(const storage<void, E>&, storage<void, E>&, ok_tag)
    {
    }

    static void move(storage<void, E>&& src, storage<void, E>& dst, err_tag)
    {
        dst.raw_construct(std::move(src.template get<E>()));
        src.destroy(err_tag());
    }

    static void copy(const storage<void, E>& src, storage<void, E>& dst, err_tag)
    {
        dst.raw_construct(src.template get<E>());
    }
};

} // namespace __detail

template<typename T, typename E>
class result {
public:
    using storage_type = __detail::storage<T, E>;
    using constructor_type = __detail::constructor<T, E>;

private:
    bool ok_;
    storage_type storage_;

public:
    result(ok_type<T> ok) : ok_(true)
    {
        storage_.construct(std::move(ok));
    }

    result(err_type<E> err) : ok_(false)
    {
        storage_.construct(std::move(err));
    }

    result(result&& other) noexcept
    {
        if (other.is_ok()) {
            constructor_type::move(std::move(other.storage_), storage_, __detail::ok_tag());
            ok_ = true;
        }
        else {
            constructor_type::move(std::move(other.storage_), storage_, __detail::err_tag());
            ok_ = false;
        }
    }

    result(const result& other)
    {
        if (other.is_ok()) {
            constructor_type::copy(other.storage_, storage_, __detail::ok_tag());
            ok_ = true;
        }
        else {
            constructor_type::copy(other.storage_, storage_, __detail::err_tag());
            ok_ = false;
        }
    }

    ~result()
    {
        if (ok_)
            storage_.destroy(__detail::ok_tag());
        else
            storage_.destroy(__detail::err_tag());
    }

    [[nodiscard]]
    bool is_ok() const
    {
        return ok_;
    }

    [[nodiscard]]
    bool is_err() const
    {
        return !ok_;
    }

    T expect(const char*) const
    {
        if (is_ok()) return expect_impl(std::is_same<T, void>());
        std::terminate();
    }

    template<
        typename Func,
        typename Ret = result<
            typename __detail::result_ok_type<typename __detail::result_of<Func>::type>::type, E>>
    requires (!std::same_as<E, void>)
    Ret map(Func func) const
    {
        return __detail::map(*this, func);
    }

    template<
        typename Func,
        typename Ret = result<
            T,
            typename __detail::result_err_type<typename __detail::result_of<Func>::type>::type>>
    Ret map_error(Func func) const
    {
        return __detail::map_error(*this, func);
    }

    template<typename Func>
    requires (!std::same_as<E, void>)
    result<T, E> then(Func func) const
    {
        return __detail::then(*this, func);
    }

    template<typename Func>
    requires (!std::same_as<E, void>)
    result<T, E> otherwise(Func func) const
    {
        return __detail::otherwise(*this, func);
    }

    template<
        typename Func,
        typename Ret = result<
            T,
            typename __detail::result_err_type<typename __detail::result_of<Func>::type>::type>>
    Ret or_else(Func func) const
    {
        return __detail::or_else_t(*this, func);
    }

    storage_type& storage()
    {
        return storage_;
    }

    const storage_type& storage() const
    {
        return storage_;
    }

    template<typename U = T>
    requires (!std::same_as<U, void>)
    U unwrap_or(const U& default_value) const
    {
        return is_ok() ? storage().template get<U>() : default_value;
    }

    template<typename U = T>
    requires (!std::same_as<U, void>)
    U unwrap() const
    {
        if (is_ok()) return storage().template get<U>();
        std::terminate();
    }

    E unwrap_err() const
    {
        if (is_err()) return storage().template get<E>();
        std::terminate();
    }

private:
    T expect_impl(std::true_type) const
    {
    }

    T expect_impl(std::false_type) const
    {
        return storage_.template get<T>();
    }
};

template<std::equality_comparable T, std::equality_comparable E>
bool operator==(const result<T, E>& lhs, const result<T, E>& rhs)
{
    if (lhs.is_ok() && rhs.is_ok())
        return lhs.storage().template get<T>() == rhs.storage().template get<T>();

    if (lhs.is_err() && rhs.is_err())
        return lhs.storage().template get<E>() == rhs.storage().template get<E>();
}

template<std::equality_comparable T, typename E>
bool operator==(const result<T, E>& lhs, ok_type<T> ok)
{
    if (!lhs.is_ok())
        return false;
    return lhs.storage().template get<T>() == ok.value;
}

template<typename E>
bool operator==(const result<void, E>& lhs, ok_type<void>)
{
    return lhs.is_ok();
}

template<typename T, std::equality_comparable E>
bool operator==(const result<T, E>& lhs, err_type<E> err)
{
    if (!lhs.is_err())
        return false;
    return lhs.storage().template get<E>() == err.value;
}

} // namespace alef::error

#endif // ALEF_CORE_ERROR_RESULT_H
