#include <iostream>
#include <string>

using std::string;

void find_numeric(const string &s) {
  const string digits = "0123456789";
  string::size_type pos = 0;
  while ((pos = s.find_first_of(digits, pos)) != string::npos) {
    std::cout << "found numeric character at index: " << pos
    << " element is " << s[pos] << std::endl;
    ++pos;
  }
}

void find_alphabetic(const string &s) {
  const string digits = "0123456789";
  string::size_type pos = 0;
  while ((pos = s.find_first_not_of(digits, pos)) != string::npos) {
    std::cout << "found alphabetic character at index: " << pos
              << " element is " << s[pos] << std::endl;
    ++pos;
  }
}

int main() {
  find_numeric("ab2c3d7R4E6");
  find_alphabetic("ab2c3d7R4E6");
}
