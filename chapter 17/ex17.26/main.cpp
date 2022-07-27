#include <iostream>
#include <string>
#include <regex>

using std::string;

int main() {
  string phone = R"((\()?(\d{3})(\))?([-. ])?(\d{3})([-. ])?(\d{4}))";
  string format = "$2.$5.$7";
  std::regex r(phone);
  string s;
  while (getline(std::cin, s)) {
    s = std::regex_replace(s, r, "", std::regex_constants::format_first_only);
    for (std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
      std::cout << it->format(format) << std::endl;
  }
}
