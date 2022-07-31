#include <iostream>
#include <fstream>

int main() {
  std::ifstream ifs("input.txt");
  char line[500] = {};
  while (ifs.getline(line, 500))
    std::cout << line << std::endl;
}
