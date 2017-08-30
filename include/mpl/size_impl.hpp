#ifndef SIZE_IMPL_HPP_
# define SIZE_IMPL_HPP_

#include <type_traits>

namespace zutils {

namespace mpl {

template<class containerSrc>
struct size_impl;

template<template<class...> class containerSrc, class... T>
struct size_impl<containerSrc<T...>> {
	using type = std::integral_constant<std::size_t, sizeof...(T)>;
};

template<class containerSrc>
using size = typename size_impl<containerSrc>::type;

}

}

#endif