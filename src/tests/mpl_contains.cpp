#include <type_traits>
#include <tuple>
#include <vector>
#include "proto_test.hh"

namespace zutils {
	namespace mpl {
		template<bool value>
		using checker_c = std::integral_constant<bool, value>;

		void test::mpl_contains() {
			assert_same_type(
				zutils::mpl::contains<std::tuple<int, float>, int>{}, checker_c<true>{}
			);
			assert_same_type(
				zutils::mpl::contains<zutils::mpl::list<int>, float>{}, checker_c<false>{}
			);
			assert_same_type(
				zutils::mpl::contains<std::vector<int>, std::allocator<int>>{}, checker_c<true>{}
			);
		}
	}
}