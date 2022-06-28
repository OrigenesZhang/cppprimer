#include <iostream>
#include "StrBlob.h"

int main() {
  StrBlob a{"A", "A", "AB"};
  StrBlob b{"A", "A", "AB"};
  std::cout << (a == b) << std::endl;
}
