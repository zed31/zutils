#include <tuple>
#include "proto_test.hh"

namespace zutils {
	namespace mpl {
		void test::mpl_reverse() {
			assert_same_type(
				zutils::mpl::reverse<zutils::mpl::list<int, float, char>>{},
				zutils::mpl::list<char, float, int>{}
			);
			assert_same_type(
				zutils::mpl::reverse<zutils::mpl::list<void *, double, float, float, char>>{},
				zutils::mpl::list<char, float, float, double, void*>{}
			);
			assert_same_type(
				zutils::mpl::reverse<std::tuple<char, float, char>>{},
				std::tuple<char, float, char>{}
			);
		}
	}
}