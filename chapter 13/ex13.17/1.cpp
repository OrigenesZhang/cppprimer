#include <iostream>

struct numbered {
  numbered() {
    mysn = current++;
  }

  int mysn;
  static int current;
};

int numbered::current = 0;

void f(numbered s) {
  std::cout << s.mysn << std::endl;
}

int main() {
  numbered a, b = a, c = b;
  f(a); // 0
  f(b); // 0
  f(c); // 0
}
