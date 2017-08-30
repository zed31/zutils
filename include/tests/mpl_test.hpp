#ifndef MPL_TEST_HPP_
# define MPL_TEST_HPP_

#include "mpl.hpp"

namespace zutils {

namespace mpl {

namespace test {

template<typename T>
struct type_wrapper {};

template<class T1, class T2>
inline void assert_same_type(T1, T2) {
	type_wrapper<T1>{} = type_wrapper<T2>{};
}

void change();
void push_back();
void size();
void push_front();
void transform();
void contains();
void at_c();
void count();
void erase_all();
void reverse();

}

}

}

#endif