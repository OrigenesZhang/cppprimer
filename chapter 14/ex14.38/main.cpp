#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

class StringRange {
public:
  StringRange(size_t l, size_t h): low(l), high(h) {}
  bool operator()(const std::string &s) const {
    return low <= s.size() && s.size() <= high;
  }
private:
  size_t low, high;
};

int main() {
  std::ifstream ifs("input.txt");
  if (!ifs.is_open()) {
    std::cerr << "Cannot open the file" << std::endl;
    return -1;
  }
  std::istream_iterator<std::string> is(ifs), eof;
  std::cout << std::count_if(is, eof, StringRange(1, 10)) << std::endl;
}
