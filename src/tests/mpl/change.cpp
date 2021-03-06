#include <tuple>
#include <vector>
#include "mpl_test.hpp"

namespace zutils {

namespace mpl {

namespace test {

void change() {
  assert_same_type(
      zutils::mpl::list<int, char, float>{},
      zutils::mpl::change<std::tuple<int, char, float>, zutils::mpl::list>{}
  );
  assert_same_type(
      std::tuple<int, char, float>{},
      zutils::mpl::change<zutils::mpl::list<int, char, float>, std::tuple>{}
  );
  assert_same_type(
      zutils::mpl::list<int, char, float>{},
      zutils::mpl::change<std::tuple<int, char, float>, zutils::mpl::list>{}
  );
  assert_same_type(
      std::vector<int>{},
      zutils::mpl::change<zutils::mpl::list<int>, std::vector>{}
  );
}

}

}

}