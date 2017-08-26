#include <tuple> 
#include "proto_test.hh"

namespace zutils {
	namespace mpl {
		void test::mpl_at_c() {
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