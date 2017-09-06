#include "array.hpp"

namespace zutils {

namespace test {

void array() {
  zutils::array<int, 3> a{1, 2, 3};
  assert(a[0] == 1 && "a[0] != 1");
  assert(a[1] == 2 && "a[1] != 2");
}

}

}