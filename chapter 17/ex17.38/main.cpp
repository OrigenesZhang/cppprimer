#include <iostream>
#include <fstream>

int main() {
  std::ifstream ifs("input.txt");
  char word[500] = {};
  while (ifs.getline(word, 500)) {
    auto sz = ifs.gcount();
    if (sz == 1) continue;
    std::cout.write(word, sz - 1);
    std::cout.write(" ", 1);
  }
  std::cout << std::endl;
}
