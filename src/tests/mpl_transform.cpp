#include <tuple>
#include "proto_test.hh"
#include "mpl_custom_list.hpp"

namespace mpl_test {
	void mpl_transform() {
		assert_same_type(
			zutils::mpl::transform<std::tuple<char, int, float>, zutils::mpl::add_pointer>{},
			std::tuple<char *, int *, float *>{}
		);
	}
}