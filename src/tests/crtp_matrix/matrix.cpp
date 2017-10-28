#include <cassert>
#include <iostream>
#include "Matrix.hpp"

namespace zutils {

namespace eval {

namespace test {

template<typename T>
static void display_matrix(zutils::eval::Matrix<T> const& m) {
  for (size_type_t j = 0; j < m.height(); ++j) {
    for (size_type_t i = 0; i < m.width(); ++i) {
      std::cout << " " << m(j, i);
    }
    std::cout << std::endl;
  }
}

template<typename T, typename Function>
static void matrix_foreach(zutils::eval::Matrix<T>& m, Function &&f) {
  for (size_type_t j = 0; j < m.height(); ++j) {
    for (size_type_t i = 0; i < m.width(); ++i) {
      f(m(j, i));
    }
  }
};

void matrix() {
  zutils::eval::Matrix<int> m(3, 3);
  auto width = m.width();
  assert(width == 3 && "Width is not correct");
  auto height = m.height();
  assert(height == 3 && "Height is not correct");
  assert(width == height && "Height and width is different");

  matrix_foreach(m, [](auto &c) { c = 3; });
  matrix_foreach(m, [](auto &c) { assert(c == 3 && "Value m(j, i) is not set"); });
  display_matrix(m);
  std::cout << "------------------------" << std::endl;
  zutils::eval::Matrix<int> m2(3, 3, 2);
  matrix_foreach(m2, [](auto &c) { assert(c == 2 && "Value m2(j, i) is not correctly set"); });
  display_matrix(m2);
  std::cout << "------------------------" << std::endl;
  zutils::eval::Matrix<int> m3(2, 3);
  display_matrix(m3);
  matrix_foreach(m3, [](auto &c) { assert(c == 0 && "Value m3(j, i) is not correctly set"); });
}

} // END namespace test

} // END namespace eval

} // END namespace zutils