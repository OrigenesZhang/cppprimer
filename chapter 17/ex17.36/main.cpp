#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  std::cout << std::left << std::setw(15) << "default format: " << std::setw(25) << std::right << 100 * sqrt(2.0) << '\n'
            << std::left << std::setw(15) << "scientific: " << std::scientific << std::setw(25) << std::right << 100 * sqrt(2.0) << '\n'
            << std::left << std::setw(15) << "fixed decimal: " << std::fixed << std::setw(25) << std::right << 100 * sqrt(2.0) << '\n'
            << std::left << std::setw(15) << "hexadecimal: " << std::hexfloat << std::setw(25) << std::right << 100 * sqrt(2.0) << '\n'
            << std::left << std::setw(15) << "use defaults: " << std::defaultfloat << std::setw(25) << std::right << 100 * sqrt(2.0) << std::endl;
}
