#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::regex;

int main() {
  string line;
  getline(std::cin, line);
  string pattern("[^c]ei");
  pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
  regex r(pattern, regex::icase);
  for (std::sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it)
    std::cout << it->str() << std::endl;
}
