#ifndef ALEF_CORE_CONTAINERS_FORWARD_LIST_NODE_H
#define ALEF_CORE_CONTAINERS_FORWARD_LIST_NODE_H

#include <type_traits>

namespace alef::containers {

template<typename T>
struct forward_list_node {
    T data;
    forward_list_node* next;

public:
    forward_list_node() = default;

    template<typename...Args>
    constexpr explicit forward_list_node(Args&&...args) : data{std::forward<Args>(args)...}
    {
    }
};

} // namespace alef::containers::forward_list

#endif // ALEF_CORE_CONTAINERS_FORWARD_LIST_NODE_H