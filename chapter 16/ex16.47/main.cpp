#include <iostream>
#include <utility>
#include <string>
#include <memory>

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2) {
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f_lvalue(std::string &t2, std::string &t1) {
  t1 = "t1";
  t2 = "t2";
}

void f_rvalue(int &&t2, int && t1) {
  std::allocator<int> alloc;
  auto p = alloc.allocate(2);
  alloc.construct(p, t2);
  alloc.construct(p + 1, t1);
  std::cout << *p << ' ' << *(p + 1) << std::endl;
  alloc.destroy(p + 1);
  alloc.destroy(p);
  alloc.deallocate(p, 2);
}

int main() {
  std::string s1, s2;
  flip(f_lvalue, s1, s2);
  std::cout << s1 << ' ' << s2 << std::endl;

  flip(f_rvalue, 1, 2);
}
