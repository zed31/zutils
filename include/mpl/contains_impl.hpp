#ifndef CONTAINS_IMPL_HPP_
# define CONTAINS_IMPL_HPP_

#include <type_traits>

namespace zutils {

namespace mpl {

template<class container, class compareType>
struct contains_impl;

template<template<class...> class container, class compareType>
struct contains_impl<container<>, compareType> {
	using type = std::integral_constant<bool, false>;
};

template<template<class...> class container, class... T, class compareType>
struct contains_impl<container<compareType, T...>, compareType> {
	using type = std::integral_constant<bool, true>;
};

template<template<class...> class container, class T1, class... T, class compareType>
struct contains_impl<container<T1, T...>, compareType> {
	using type = typename contains_impl<container<T...>, compareType>::type;
};

template<class container, class compareType>
using contains = typename contains_impl<container, compareType>::type;

} // End mpl

} // End zutils

#endif