#include <iostream>
#include "StrBlob.h"

int main() {
  StrBlob sb1{"a", "b", "c"}, sb2{"a", "c", "b"};
  if (sb1 < sb2) {
    for (auto iter = sb1.begin(); iter != sb1.end(); iter.incr())
      std::cout << iter.deref() << " ";
    std::cout << std::endl;
  }
}