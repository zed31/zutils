#include <tuple>
#include "mpl_test.hpp"

namespace zutils {
	namespace mpl {
		void test::transform() {
			assert_same_type(
				zutils::mpl::transform<std::tuple<char, int, float>, zutils::mpl::add_pointer>{},
				std::tuple<char *, int *, float *>{}
			);
		}
	}
}