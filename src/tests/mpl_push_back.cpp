#include <tuple>
#include "proto_test.hh"

namespace mpl_test {
	void test_mpl_push_back() {
		assert_same_type(
			zutils::mpl::list<int, float, double>{},
			zutils::mpl::push_back<zutils::mpl::list<int, float>, double>{}
		);
		assert_same_type(
			zutils::mpl::list<int, float, double, char, char, int, float>{},
			zutils::mpl::push_back<zutils::mpl::list<int, float>, double, char, char, int, float>{}
		);
		assert_same_type(
			std::tuple<int, float, double, char, char, int, float>{},
			zutils::mpl::push_back<std::tuple<int, float>, double, char, char, int, float>{}
		);
	}
}