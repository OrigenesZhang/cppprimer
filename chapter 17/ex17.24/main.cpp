#include <iostream>
#include <string>
#include <regex>

using std::string;

int main() {
  string phone = R"((\()?(\d{3})(\))?([-. ])?(\d{3})([-. ])?(\d{4}))";
  string format = "$2.$5.$7";
  std::regex r(phone);
  string s;
  while (getline(std::cin, s))
    std::cout << std::regex_replace(s, r, format) << std::endl;
}
