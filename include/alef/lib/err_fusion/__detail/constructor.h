#ifndef ALEF_LIB_ERR_FUSION_DETAIL_CONSTRUCTOR_H
#define ALEF_LIB_ERR_FUSION_DETAIL_CONSTRUCTOR_H

#include "alef/lib/err_fusion/__detail/storage.h"

namespace alf::ef::__detail {

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

} // namespace alf::ef::__detail

#endif // ALEF_LIB_ERR_FUSION_DETAIL_CONSTRUCTOR_H
