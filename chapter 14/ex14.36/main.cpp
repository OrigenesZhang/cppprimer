#include <iostream>
#include <string>
#include <vector>

class ReadString {
public:
  ReadString(std::istream &i = std::cin): is(i) {}
  std::string operator()() {
    std::string s;
    getline(is, s);
    return is ? s : "";
  }
private:
  std::istream &is;
};

int main() {
  ReadString rs;
  std::vector<std::string> lines;
  for (std::string s; !(s = rs()).empty(); )
    lines.push_back(s);
  for (const auto &s : lines)
    std::cout << s << std::endl;
}
