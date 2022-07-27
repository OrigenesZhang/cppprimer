#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex r("[^c]ei");
  std::string s;
  while (std::cin >> s) {
    if (std::regex_match(s, r))
      std::cout << s << " is okay!" << std::endl;
    else
      std::cout << s << " is not okay!" << std::endl;
  }
}
