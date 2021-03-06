#include <iostream>
#include "transfer_test.hpp"
#include "mpl_test.hpp"
#include "matrix_test.hpp"
#include "array_test.hpp"

int main() {
  zutils::mpl::test::change();
  zutils::mpl::test::push_back();
  zutils::mpl::test::size();
  zutils::mpl::test::push_front();
  zutils::mpl::test::transform();
  zutils::mpl::test::contains();
  zutils::mpl::test::at_c();
  zutils::mpl::test::count();
  zutils::mpl::test::erase_all();
  zutils::mpl::test::reverse();
  zutils::mpl::test::join();
  zutils::transfer::test::meta_function();
  zutils::eval::test::matrix();
  zutils::test::array();
  std::cout << "All passed" << std::endl;
}