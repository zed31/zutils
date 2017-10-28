#include <iostream>
#include "array.hpp"

namespace zutils {

namespace test {

void array() {
  zutils::array<int, 4> a{1, 2, 3, 4};
  std::cout << a[3] << std::endl;
  //assert(a[0] == 1 && "a[0] != 1");
  //assert(a[1] == 2 && "a[1] != 2");
}

}

}