#ifndef ZUTILS_JOIN_IMPL_HPP
#define ZUTILS_JOIN_IMPL_HPP

namespace zutils {

namespace mpl {

template<typename containerDest, typename containerSrc>
struct join_impl;

template<template<class...> class containerDest, typename... T,
        template<class...> class containerSrc, typename... V>
struct join_impl<containerDest<T...>, containerSrc<V...>> {
  using type = containerDest<T..., V...>;
};

template<typename containerDest, typename containerSrc>
using join = typename join_impl<containerDest, containerSrc>::type;

} // End namespace mpl

} // End namespace zutils

#endif //ZUTILS_JOIN_IMPL_HPP
