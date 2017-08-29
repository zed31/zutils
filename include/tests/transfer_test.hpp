#ifndef TRANSFER_TEST_HPP_
# define TRANSFER_TEST_HPP_

#include "meta_container.hpp"
#include "meta_function.hpp"
#include "type_wrapper.hpp"
#include "transfer_functions.hpp"

namespace zutils {
	namespace transfer {
		namespace test {
			template<typename T>
			void assert_same_type(T, T) {};
			
			void meta_function();
		}
	}
}

#endif