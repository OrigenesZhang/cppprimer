#include <iostream>
#include <cmath>

int main() {
  std::cout << "default format: " << 100 * sqrt(2.0) << '\n'
  << "scientific: " << std::scientific << 100 * sqrt(2.0) << '\n'
  << "fixed decimal: " << std::fixed << 100 * sqrt(2.0) << '\n'
  << "hexadecimal: " << std::hexfloat << 100 * sqrt(2.0) << '\n'
  << "use defaults: " << std::defaultfloat << 100 * sqrt(2.0) << std::endl;
}
