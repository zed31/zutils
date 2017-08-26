#ifndef TYPE_WRAPPER_HPP_
# define TYPE_WRAPPER_HPP_

namespace zutils {
	namespace transfer {
		template<typename T>
		struct type_wrapper {
			using type = T;
		};
	}
}

#endif