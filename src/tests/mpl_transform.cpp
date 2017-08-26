#include <tuple>
#include "proto_test.hh"

namespace zutils {
	namespace mpl {
		void test::mpl_transform() {
			assert_same_type(
				zutils::mpl::transform<std::tuple<char, int, float>, zutils::mpl::add_pointer>{},
				std::tuple<char *, int *, float *>{}
			);
		}
	}
}