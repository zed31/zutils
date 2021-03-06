#include <type_traits>
#include <tuple>
#include <vector>
#include "mpl_test.hpp"

namespace zutils {

namespace mpl {

namespace test {

template<std::size_t value>
using checker_c = typename std::integral_constant<std::size_t, value>::type;

void count() {
  assert_same_type(
      zutils::mpl::count<std::tuple<int, float, int>, int>{},
      checker_c<2>{}
  );
  assert_same_type(
      zutils::mpl::count<zutils::mpl::list<int, float, int>, int>{},
      checker_c<2>{}
  );
  assert_same_type(
      zutils::mpl::count<std::tuple<int>, int>{},
      checker_c<1>{}
  );
  assert_same_type(
      zutils::mpl::count<std::tuple<std::vector<int>>, std::vector<int>>{},
      checker_c<1>{}
  );

}

} // End namespace test

} // End namespace mpl

} // End namespace zutils