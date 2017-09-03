#ifndef TYPE_WRAPPER_HPP_
# define TYPE_WRAPPER_HPP_

#include <type_traits>

namespace zutils {

namespace transfer {

template<typename T>
struct type_wrapper {
  using type = T;
};

template<typename T>
type_wrapper<T> m_type{};

template<std::size_t value>
using size_t_wrapper = std::integral_constant<std::size_t, value>;

template<int value>
using int_wrapper = std::integral_constant<int, value>;

template<char value>
using char_wrapper = std::integral_constant<char, value>;

}

}

#endif