#include <iostream>
#include <string>
#include <cstring>

int main() {
  char *ptr = new char[strlen("a " "b") + 1]();
  strcat(ptr, "a ");
  strcat(ptr, "b");
  std::cout << ptr << std::endl;
  delete [] ptr;

  std::string a = "a ", b = "b";
  std::cout << a + b << std::endl;
}