#include <iostream>
#include <string>
#include <sstream>

template <typename T> std::string debug_rep(const T& t);
template <typename T> std::string debug_rep(T* p);

std::string debug_rep(char*);
std::string debug_rep(const std::string&);
std::string debug_rep(const char*);

template <typename T>
std::string debug_rep(const T& t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T>
std::string debug_rep(T* p) {
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " null pointer";
  return ret.str();
}

std::string debug_rep(const std::string &s) {
  return '"' + s + '"';
}

std::string debug_rep(char *p) {
  return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
  return debug_rep(std::string(p));
}

int main() {
  std::cout << debug_rep("hi world") << std::endl;
  std::string s = "hi world";
  std::cout << debug_rep(&s) << std::endl;
}
