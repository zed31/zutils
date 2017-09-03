#include <vector>
#include <tuple>
#include <map>
#include <memory>
#include "mpl_test.hpp"

namespace zutils {

namespace mpl {

namespace test {

template<std::size_t value>
using checker_c = typename std::integral_constant<std::size_t, value>;

void size() {
  assert_same_type(
      zutils::mpl::size<std::tuple<int, float, char, double *>>{}, checker_c<4>{}
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

} // End namespace test

} // End namespace mpl

} // End namespace zutils
