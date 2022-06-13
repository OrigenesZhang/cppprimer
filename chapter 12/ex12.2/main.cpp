#include <iostream>
#include "str_blob.h"

int main() {
  const StrBlob csb{"1", "2", "3"};
  StrBlob sb{"1", "2", "3"};
  std::cout << csb.front() << ' ' << csb.back() << std::endl;
  sb.back() = "x";
  std::cout << sb.front() << ' ' << sb.back() << std::endl;
}
