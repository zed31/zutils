#pragma once

#include "erase_all_impl.hpp"
#include "push_front_impl.hpp"

namespace zutils {
	namespace mpl {
		template<class container>
		struct no_duplicates_impl;

		template<template<class...> class container>
		struct no_duplicates_impl<container<>> {
			using type = container<>;
		};

		template<template<class...> class container, class T1, class... T>
		struct no_duplicates_impl<container<T1, T...>> {
			using containerCleaned = typename erase_all_impl<container<T...>, T1>::type;
			using rest = typename no_duplicates_impl<containerCleaned>::type;
			using type = typename push_front_impl<rest, T1>::type;
		};

		template<class container>
		using no_duplicates = typename no_duplicates_impl<container>::type;
	}
}