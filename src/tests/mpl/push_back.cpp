#include <tuple>
#include "mpl_test.hpp"

namespace zutils {

namespace mpl {

namespace test {

void push_back() {
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

} // End namespace test

} // End namespace mpl

} // End namespace zutils