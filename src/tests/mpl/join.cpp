#include <tuple>
#include "mpl_test.hpp"

namespace zutils {

namespace mpl {

namespace test {

void join() {
  assert_same_type(std::tuple<int, char, float>{}, zutils::mpl::join<std::tuple<int>, std::tuple<char, float>>{});
  assert_same_type(zutils::mpl::list<int, char, float>{}, zutils::mpl::join<zutils::mpl::list<int>, std::tuple<char, float>>{});
  assert_same_type(zutils::mpl::list<int>{}, zutils::mpl::join<zutils::mpl::list<int>, zutils::mpl::list<>>{});
  assert_same_type(
      zutils::mpl::list<int, char, float>{},
      zutils::mpl::reverse<zutils::mpl::join<zutils::mpl::list<float>, zutils::mpl::list<char, int>>>{}
  );
}

} // END namespace test

} // END namespace mpl

} // END namepsace zutils

