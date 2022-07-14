#include <iostream>
#include <string>
#include "Blob.h"

int main() {
  std::string s[] = {"abc", "efg", "123", "xyz"};
  Blob<std::string> blob(std::begin(s), std::end(s));
  for (size_t i = 0; i != blob.size(); ++i)
    std::cout << blob[i] << " ";
  std::cout << std::endl;
}
