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
    std::smatch m;
    std::regex_search(s, m, r);
    if (!m.empty())
      std::cout << m.prefix() << m.format(format) << std::endl;
    else
      std::cout << "No match!" << std::endl;
  }
}
