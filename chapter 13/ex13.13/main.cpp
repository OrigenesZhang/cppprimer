#include <iostream>
#include <vector>

struct X {
  X() { std::cout << "X()" << std::endl; }
  X(const X&) { std::cout << "X(const X&)" << std::endl; }
  X& operator=(const X&) {
    std::cout << "X& operator=(const X&)" << std::endl;
    return *this;
  }
  ~X() { std::cout << "~X()" << std::endl; }
};

void f(X x) {
  std::cout << "f(X x)" << std::endl;
}

void g(X& x) {
  std::cout << "g(X& x)" << std::endl;
}

int main() {
  std::vector<X> v;
  X x1;
  v.push_back(x1);
  f(x1);
  g(x1);
  auto x_ptr = new X;
  delete x_ptr;
}
