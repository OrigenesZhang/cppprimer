#include <iostream>
#include <string>
#include <sstream>

template <typename T> std::string debug_rep(T* t);
template <> std::string debug_rep(const char *t);
template <> std::string debug_rep(char *t);

template <typename T>
std::string debug_rep(T *t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <>
std::string debug_rep(const char *t) {
  std::string ret(t);
  return ret;
}

template <>
std::string debug_rep(char *t) {
  std::string ret(t);
  return ret;
}

int main() {
  const char *p = "Hello world";
  std::cout << debug_rep(p) << std::endl;
}
