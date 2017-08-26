#ifndef PUSH_FRONT_IMPL_HPP_
# define PUSH_FRONT_IMPL_HPP_

namespace zutils {
	namespace mpl {
		template<class container, class... T>
		struct push_front_impl;

		template<template<class...> class container, class... T, class... insert>
		struct push_front_impl<container<T...>, insert...> {
			using type = container<insert..., T...>;
		};

		template<class container, class... T>
		using push_front = typename push_front_impl<container, T...>::type;
	}
}

#endif