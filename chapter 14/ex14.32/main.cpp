#include <iostream>
#include "StrBlobPtr_Ptr.h"

int main() {
  StrBlob sb{"hello", "world"};
  StrBlobPtr iter(sb);
  StrBlobPtr_Ptr ptr(&iter);
  std::cout << ptr->operator*() << std::endl;
}
