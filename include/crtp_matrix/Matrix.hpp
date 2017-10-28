#ifndef ZUTILS_MATRIX_HPP
#define ZUTILS_MATRIX_HPP

#include <iostream>
#include <vector>
#include <cassert>

namespace zutils {

namespace eval {

using size_type_t = std::size_t;

template<typename T>
class Matrix {
public:
  /* Default constructors */
  Matrix(size_type_t height, size_type_t width, T const& t = T{}) noexcept;
  Matrix(Matrix const& m)                     = default;
  Matrix &operator=(Matrix const& m)          = default;
  Matrix(Matrix&& m) noexcept                 = default;
  Matrix &operator=(Matrix&& m) noexcept      = default;

  /* Overloaded operators */
  T &operator()(size_type_t height, size_type_t width);
  T const &operator()(size_type_t height, size_type_t width) const;

  /* Getter for width and height */
  inline size_type_t height() const;
  inline size_type_t width() const;
private:
  size_type_t m_width;
  size_type_t m_height;
  std::vector<T> m_data;
};

template<typename T>
Matrix<T>::Matrix(size_type_t height, size_type_t width, T const& t) noexcept
    : m_width{ width }, m_height{ height }, m_data( width * height, t ) {}

template<typename T>
T &Matrix<T>::operator()(size_type_t height, size_type_t width) {
  assert(width < m_width && height < m_height && "Matrix<T>: Index out of bound");
  return m_data[height * m_width + width];
}

template<typename T>
T const &Matrix<T>::operator()(size_type_t height, size_type_t width) const {
  assert(width < m_width && height < m_height && "Matrix<T>: Index out of bound");
  return m_data[height * m_width + width];
}

template<typename T>
size_type_t Matrix<T>::width() const {
  return m_width;
}

template<typename T>
size_type_t Matrix<T>::height() const {
  return m_height;
}

} // END namespace matrix

} // END namespace zutils

#endif //ZUTILS_MATRIX_HPP
