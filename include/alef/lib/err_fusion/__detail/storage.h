#ifndef ALEF_LIB_ERR_FUSION_DETAIL_STORAGE_H
#define ALEF_LIB_ERR_FUSION_DETAIL_STORAGE_H

#include "alef/lib/err_fusion/__detail/tag.h"
#include "alef/lib/err_fusion/__detail/err_type.h"
#include "alef/lib/err_fusion/__detail/ok_type.h"

namespace alf::ef::__detail {

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

    void construct(alf::ef::ok_type<T> ok)
    {
        new (&storage_) T(ok.value);
        initialized_ = true;
    }

    void construct(alf::ef::err_type<E> err)
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
    void construct(alf::ef::ok_type<void>) { initialized_ = true; }

    void construct(alf::ef::err_type<E> err)
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

} // namespace alf::ef::__detail

#endif // ALEF_LIB_ERR_FUSION_DETAIL_STORAGE_H
