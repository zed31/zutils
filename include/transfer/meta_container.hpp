#ifndef META_CONTAINER_HPP_
# define META_CONTAINER_HPP_

namespace zutils {

namespace transfer {

template<template<typename...> class f>
struct meta_container {
	template<typename... T>
	using apply = f<T...>;
};

}

}

#endif