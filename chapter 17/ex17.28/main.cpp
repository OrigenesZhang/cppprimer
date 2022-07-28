#include <iostream>
#include <random>

unsigned uniform_rand_uint() {
  static std::default_random_engine e;
  static std::uniform_int_distribution<unsigned> u;
  return u(e);
}

int main() {
  for (int i = 0; i != 10; ++i)
    std::cout << uniform_rand_uint() << std::endl;
}
