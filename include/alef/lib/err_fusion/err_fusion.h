#ifndef ALEF_LIB_ERR_FUSION_ERR_FUSION_H
#define ALEF_LIB_ERR_FUSION_ERR_FUSION_H

#include "alef/lib/err_fusion/__detail/general.h"
#include "alef/lib/err_fusion/__detail/operators.h"

namespace alf::ef {

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

} // namespace alf::ef

#endif // ALEF_LIB_ERR_FUSION_ERR_FUSION_H
