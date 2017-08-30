#ifndef META_FUNCTION_HPP_
# define META_FUNCTION_HPP_

namespace zutils {

namespace mpl {

template<class T>
using add_pointer = T*;

template<class T>
using add_const_pointer = T const*;

/*
** Those meta functions are used to
** create bridge between mpl world and "runtime" world
** it's just an example, u can create others while they're
** follows the same semantic.
*/

template<class T>
struct add_pointer_meta {
	using type = T*;
};

template<class T>
struct add_const_pointer_meta {
	using type = T const *;
};

} // End mpl

} // End zutils

#endif