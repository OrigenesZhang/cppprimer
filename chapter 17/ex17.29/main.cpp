#include <iostream>
#include <random>

unsigned uniform_rand_uint(unsigned seed = 0) {
  static std::default_random_engine e(seed);
  static std::uniform_int_distribution<unsigned> u;
  return u(e);
}

int main() {
  for (int i = 0; i != 10; ++i)
    std::cout << uniform_rand_uint(3) << std::endl;
}
