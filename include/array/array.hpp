#ifndef ZUTILS_ARRAY_HPP
#define ZUTILS_ARRAY_HPP

#include <cstddef>
#include <initializer_list>
#include <cassert>

namespace zutils {

//Data storage
template<typename T, std::size_t N>
struct storage {
  T value;
  storage<T, N - 1> next;
};

//Stoping recursion
template<typename T>
struct storage<T, 1> {
  T value;
};

//Main class
template<typename T, std::size_t N>
class array {
public:
  array(std::initializer_list<T> l) {
    assert(l.size() == N && "Error : Mismatch size parameters");
    auto size = N;
    auto it = l.begin();
    auto storage_tmp = &m_storage;
    while (size > 0) {
      storage_tmp->value = (*it);
      storage_tmp = reinterpret_cast<storage<T, N> *>(&storage_tmp->next);
      --size;
      ++it;
    }
  }

  auto &operator[](std::size_t idx) {
    assert(idx < N && "Index out of bound");
    auto &storage_tmp = m_storage;
    while (idx > 0) {
      storage_tmp = reinterpret_cast<storage<T, N> &>(storage_tmp.next);
      --idx;
    }
    return storage_tmp.value;
  }
private:
  storage<T, N> m_storage;
};

}

#endif //ZUTILS_ARRAY_HPP
