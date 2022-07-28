#include <iostream>
#include <random>

unsigned uniform_rand_uint(unsigned l, unsigned r, unsigned seed = 0) {
  static std::default_random_engine e(seed);
  static std::uniform_int_distribution<unsigned> u(l, r);
  return u(e);
}

int main() {
  for (int i = 0; i != 10; ++i)
    std::cout << uniform_rand_uint(1, 10, 2) << std::endl;
}
