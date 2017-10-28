#include <tuple>
#include "mpl_test.hpp"

namespace zutils {

namespace mpl {

namespace test {

void push_front() {
  assert_same_type(
      zutils::mpl::list<double, int, float>{},
      zutils::mpl::push_front<zutils::mpl::list<int, float>, double>{}
  );
  assert_same_type(
      zutils::mpl::list<double, unsigned, char, int, float, int, float>{},
      zutils::mpl::push_front<zutils::mpl::list<int, float>, double, unsigned, char, int, float>{}
  );
  assert_same_type(
      std::tuple<double, char, char, int, float, int, float>{},
      zutils::mpl::push_front<std::tuple<int, float>, double, char, char, int, float>{}
  );
}

} // End namespace test

} // End namespace mpl

} // End namespace zutils