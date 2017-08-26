#include <tuple> 
#include "mpl_test.hpp"

namespace zutils {
	namespace mpl {
		void test::at_c() {
			static_assert(
				std::is_same<
					zutils::mpl::at_c<std::tuple<int, char, float>, 1>,
					char
				>::value, ""
			);
			static_assert(
				std::is_same<
					zutils::mpl::at_c<std::tuple<int, char, float>, 2>,
					float
				>::value, ""
			);
			static_assert(
				std::is_same<
					zutils::mpl::at_c<zutils::mpl::list<int, char, float>, 1>,
					char
				>::value, ""
				);
			static_assert(
				std::is_same<
					zutils::mpl::at_c<zutils::mpl::list<int, char, float>, 0>,
					int
				>::value, ""
			);
		}
	}
}