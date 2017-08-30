#ifndef TRANSFER_FUNCTION_HPP_
# define TRANSFER_FUNCTION_HPP_

#include "type_wrapper.hpp"

namespace zutils {
	namespace transfer {
		template<class f, class... T>
		auto apply_meta_function(T... t) {
			return m_type<
				typename f::template apply<typename decltype(t)::type...>::type
			>;
		};

        template<template<class...> class f, class... T>
        auto apply_template(T... t) {
            return m_type<
                f<typename decltype(t)::type...>
            >;
        };
	}
}

#endif
