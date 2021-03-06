#ifndef AT_IMPL_HPP_
# define AT_IMPL_HPP_

namespace zutils {

namespace mpl {

template<class container, unsigned pos>
struct at_impl;

template<template<class...> class container, class T1, class... T>
struct at_impl<container<T1, T...>, 0> {
	using type = T1;
};

template<template<class...> class container, class T1, class... T, unsigned pos>
struct at_impl<container<T1, T...>, pos> {
	using type = typename at_impl<container<T...>, pos - 1>::type;
};

template<class container, unsigned pos>
using at_c = typename at_impl<container, pos>::type;

template<typename container, unsigned pos>
struct at_transfer_c {
	using type = typename at_impl<container, pos>::type;
};

}// End mpl

}// End zutil

#endif