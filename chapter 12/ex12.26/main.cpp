#include <iostream>
#include <memory>
#include <string>

int main() {
  size_t n;
  std::cin >> n;
  std::allocator<std::string> a;
  auto const p = a.allocate(n);
  auto q = p;
  std::string s;
  while (q != p + n && std::cin >> s)
    a.construct(q++, s);
  while (q != p) {
    std::cout << *--q << ' ';
    a.destroy(q);
  }
  a.deallocate(p, n);
}
