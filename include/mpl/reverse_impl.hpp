#ifndef REVERSE_IMPL_HPP_
# define REVERSE_IMPL_HPP_

#include "push_back_impl.hpp"

namespace zutils {

namespace mpl {

template<typename container>
struct reverse_impl;

template<template<class...> class container>
struct reverse_impl<container<>> {
	using type = container<>;
};

template<template<class...> class container, class T1, class... T>
struct reverse_impl<container<T1, T...>> {
	using rest = typename reverse_impl<container<T...>>::type;
	using type = typename push_back_impl<rest, T1>::type;
};

template<class container>
using reverse = typename reverse_impl<container>::type;

} //End mpl

} // End zutils

#endif