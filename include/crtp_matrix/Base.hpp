#ifndef ZUTILS_BASE_HPP
#define ZUTILS_BASE_HPP

#include <cstddef>

namespace zutils {

namespace eval {

struct BaseCoreAccess {
  template<typename T>
  static auto eval(T &o, std::size_t height, std::size_t width) { return o.eval_impl(height, width); };
};

template<typename T>
class Base {
public:
  auto eval(std::size_t height, std::size_t width) const {
    return BaseCoreAccess::eval(derived(), height, width);
  }
private:
  friend BaseCoreAccess;
  auto eval_impl(std::size_t, std::size_t) const {
    return 1;
  }
  auto &derived() { return static_cast<T &>(*this); };
  auto &derived() const { return static_cast<T const&>(*this); };
};

} // END namespace eval

} // END namespace zutils

#endif //ZUTILS_BASE_HPP
