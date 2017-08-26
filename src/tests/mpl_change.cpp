#include <tuple>
#include <vector>
#include "proto_test.hh"

namespace mpl_test {
	void test_mpl_change() {
		assert_same_type(
			zutils::mpl::list<int, char, float>{},
			zutils::mpl::change<std::tuple<int, char, float>, zutils::mpl::list>{}
		);
		assert_same_type(
			std::tuple<int, char, float>{},
			zutils::mpl::change<zutils::mpl::list<int, char, float>, std::tuple>{}
		);
		assert_same_type(
			zutils::mpl::list<int, char, float>{},
			zutils::mpl::change<std::tuple<int, char, float>, zutils::mpl::list>{}
		);
		assert_same_type(
			std::vector<int>{},
			zutils::mpl::change<zutils::mpl::list<int>, std::vector>{}
		);
	}
}