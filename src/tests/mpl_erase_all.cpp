#include <tuple>
#include "proto_test.hh"

namespace mpl_test {
	void mpl_erase_all() {
		assert_same_type(
			zutils::mpl::erase_all<std::tuple<int, int, int, float>, int>{},
			std::tuple<float>{}
		);
		assert_same_type(
			zutils::mpl::erase_all<std::tuple<int, int, int>, int>{},
			std::tuple<>{}
		);
		assert_same_type(
			zutils::mpl::erase_all<zutils::mpl::list<int, int, int>, int>{},
			zutils::mpl::list<>{}
		);
		assert_same_type(
			zutils::mpl::erase_all<zutils::mpl::list<int, int, int, float>, int>{},
			zutils::mpl::list<float>{}
		);
		assert_same_type(
			zutils::mpl::erase_all<zutils::mpl::list<float, int, int, float>, int>{},
			zutils::mpl::list<float, float>{}
		);
	}
}