#ifndef CHANGE_IMPL_HPP_
# define CHANGE_IMPL_HPP_

namespace zutils {

namespace mpl {

template<class containerSrc, template<class...> class containerDest>
struct change_impl;

template<template<class...> class containerSrc, class... T, template<class...> class containerDest>
struct change_impl<containerSrc<T...>, containerDest> {
	using type = containerDest<T...>;
};

template<class containerSrc, template<class...> class containerDest>
using change = typename change_impl<containerSrc, containerDest>::type;

}

}

#endif