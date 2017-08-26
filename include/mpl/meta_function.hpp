#pragma once

namespace zutils {
	namespace mpl {
		template<class T>
		using add_pointer = T*;

		template<class T>
		using add_const_pointer = T const*;
	}
}