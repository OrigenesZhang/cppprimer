#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::regex;
using std::sregex_iterator;
using std::smatch;

bool valid(const smatch &m) {
  if (m[1].matched)
    return m[3].matched && (!m[4].matched || m[4].str() == " ");
  return !m[3].matched && m[4].str() == m[6].str();
}

int main() {
  string phone = R"((\()?(\d{3})(\))?([-.]|\s+)?(\d{3})([-.]|\s+)?(\d{4}))";
  regex r(phone);
  smatch m;
  string s;
  while (getline(std::cin, s)) {
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
      if (valid(*it))
        std::cout << "valid: " << it->str() << std::endl;
      else
        std::cout << "not valid: " << it->str() << std::endl;
  }
}
