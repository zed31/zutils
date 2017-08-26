#include <vector>
#include <tuple>
#include <map>
#include <type_traits>
#include <memory>
#include "proto_test.hh"

template<std::size_t value>
using checker_c = typename std::integral_constant<std::size_t, value>;

namespace mpl_test {
	void mpl_size() {
		assert_same_type(
			zutils::mpl::size<std::tuple<int, float, char, double*>>{}, checker_c<4>{}
		);
		assert_same_type(
			zutils::mpl::size<std::vector<int>>{}, checker_c<2>{}
		);
		assert_same_type(
			zutils::mpl::size<zutils::mpl::list<int, checker_c<3>>>{}, checker_c<2>{}
		);
		assert_same_type(
			zutils::mpl::size<std::unique_ptr<int>>{}, checker_c<2>{}
		);
		assert_same_type(
			zutils::mpl::size<std::map<int, char>>{}, checker_c<4>{}
		);
	}
}
