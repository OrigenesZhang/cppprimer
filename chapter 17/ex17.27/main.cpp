#include <iostream>
#include <string>
#include <regex>

using std::string;

int main() {
  string pattern = R"((\d{5})([-. ])?(\d{4}))", fmt = "$1-$3";
  std::regex r(pattern);
  string s;
  while (getline(std::cin, s))
    std::cout << std::regex_replace(s, r, fmt, std::regex_constants::format_no_copy) << std::endl;

}
