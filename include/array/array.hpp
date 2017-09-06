#ifndef ZUTILS_ARRAY_HPP
#define ZUTILS_ARRAY_HPP

#include <cstddef>
#include <utility>
#include <initializer_list>
#include <cassert>

namespace zutils {

//Data storage
template<typename T, std::size_t>
struct value {
  T value;
};

//Recursion value storage
template<typename T, typename Size>
struct storage;

template<typename T, std::size_t... Size>
struct storage<T, std::integer_sequence<std::size_t, Size...>> : value<T, Size>... {};

//Main class
template<typename T, std::size_t N>
class array {
public:
  array(std::initializer_list<T> const& l) {
    assert(l.size() == N && "Mismatch initialization");
    auto s = getStorage();
    auto itL = l.begin();
    for (std::size_t i = 0; i < l.size(); ++i) {
      s[i] = *itL;
      ++itL;
    }
  }
  T &operator[](std::size_t idx) {
    assert(idx < N && "Index out of bound");
    return getStorage()[idx];
  }
  T const &operator[](std::size_t idx) const {
    assert(idx < N && "Index out of bound");
    return getStorage()[idx];
  }
private:
  auto getStorage() {
    return reinterpret_cast<T *>(&m_storage);
  }
  auto getStorage() const {
    return reinterpret_cast<T *>(&m_storage);
  }
  storage<T, std::make_index_sequence<N>> m_storage;
};

}

#endif //ZUTILS_ARRAY_HPP
