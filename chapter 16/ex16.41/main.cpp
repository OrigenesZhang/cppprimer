#include <iostream>
#include <type_traits>
#include <limits>

template<size_t, bool> struct promote;

template<> struct promote<sizeof(uint8_t), false> { using type = uint16_t; };
template<> struct promote<sizeof(uint16_t), false> { using type = uint32_t; };
template<> struct promote<sizeof(uint32_t), false> { using type = uint64_t; };
template<> struct promote<sizeof(int8_t), true> { using type = int16_t; };
template<> struct promote<sizeof(int16_t), true> { using type = int32_t; };
template<> struct promote<sizeof(int32_t), true> { using type = int64_t; };

template <typename T>
using promote_t = typename promote<sizeof(T), std::is_signed<T>::value>::type;

template <typename T>
promote_t<T> sum(T x, T y) {
  return static_cast<promote_t<T>>(x) + y;
}

int main() {
  auto x = std::numeric_limits<int>::max();
  std::cout << x << " + " << x << " = " << sum(x, x) << std::endl;
}
