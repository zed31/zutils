#ifndef META_FUNCTION_HPP_
# define META_FUNCTION_HPP_

namespace zutils {
	namespace mpl {
		template<class T>
		using add_pointer = T*;

		template<class T>
		using add_const_pointer = T const*;
	}
}

#endif