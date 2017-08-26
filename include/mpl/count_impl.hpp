#pragma once

#include <type_traits>
#include "size_impl.hpp"
#include "erase_all_impl.hpp"

namespace zutils {
	namespace mpl {
		template<class container, class typeOccur>
		using count = typename std::integral_constant<
			std::size_t, 
			size<container>::value - size<erase_all<container, typeOccur>>::value
		>::type;
	}
}