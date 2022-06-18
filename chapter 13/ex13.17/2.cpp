#include <iostream>

struct numbered {
  numbered() {
    mysn = current++;
  }

  numbered(const numbered& rhs) {
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
  f(a); // 3
  f(b); // 4
  f(c); // 5
}
