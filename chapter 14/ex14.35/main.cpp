#include <iostream>
#include <string>

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
  std::cout << rs() << std::endl;
}
