#ifndef TRANSFORM_IMPL_HPP_
# define TRANSFORM_IMPL_HPP_

namespace zutils {

namespace mpl {

template<class container, template<class...> class metaFunction>
struct transform_impl;

template<template<class...> class container, class... T, template<class...> class metaFunction>
struct transform_impl<container<T...>, metaFunction> {
	using type = container<metaFunction<T>...>;
};

template<class container, template<class...> class metaFunction>
using transform = typename transform_impl<container, metaFunction>::type;

}

}

#endif