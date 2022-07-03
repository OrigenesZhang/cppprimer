#include <iostream>
#include <functional>
#include <map>
#include <string>

int main() {
  std::map<std::string, std::function<int(int, int)>> bin_ops = {
      {"+", std::plus<>()},
      {"-", std::minus<>()},
      {"*", std::multiplies<>()},
      {"/", std::divides<>()},
      {"%", std::modulus<>()}
  };
  int x, y;
  std::string op;
  std::cin >> x >> op >> y;
  std::cout << bin_ops[op](x, y) << std::endl;
}
