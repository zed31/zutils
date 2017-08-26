#ifndef PUSH_BACK_IMPL_HPP_
# define PUSH_BACK_IMPL_HPP_

namespace zutils {
	namespace mpl {
		template<class container, class... T>
		struct push_back_impl;

		template<template<class...> class container, class... T, class... insert>
		struct push_back_impl<container<T...>, insert...> {
			using type = container<T..., insert...>;
		};

		template<class container, class... insert>
		using push_back = typename push_back_impl<container, insert...>::type;
	}
}

#endif