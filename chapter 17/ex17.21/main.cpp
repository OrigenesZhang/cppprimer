#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

bool valid(const std::smatch &m) {
  if (m[1].matched)
    return m[3].matched && (!m[4].matched || m[4].str() == " ");
  return !m[3].matched && m[4].str() == m[6].str();
}

std::string format(const std::smatch &m) {
  return '+' + m[2].str() + '-' + m[5].str() + '-' + m[7].str();
}

int main() {
  std::ifstream is("data.in");
  std::string line, word;
  std::vector<PersonInfo> people;
  while (getline(is, line)) {
    PersonInfo info;
    std::istringstream record(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }
  std::ofstream os("data.out", std::ofstream::app);
  std::string phone = R"((\()?(\d{3})(\))?([-. ])?(\d{3})([-. ])?(\d{4}))";
  std::regex r(phone);
  std::smatch m;
  for (const auto &entry : people) {
    std::ostringstream formatted, badNums;
    for (const auto &nums : entry.phones) {
      for (std::sregex_iterator it(nums.begin(), nums.end(), r), end_it; it != end_it; ++it) {
        if (!valid(*it)) {
          badNums << " " << nums;
        } else {
          formatted << " " << format(*it);
        }
      }
    }
    if (badNums.str().empty())
      os << entry.name << " " << formatted.str() << std::endl;
    else
      std::cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << std::endl;
  }
  os.close();
  return 0;
}
