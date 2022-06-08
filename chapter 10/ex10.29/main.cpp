#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>

using std::string;

int main() {
  std::ifstream fin("text.in");
  std::istream_iterator<string> is(fin), eof;
  std::vector<string> vec(is, eof);
  for (const auto &x : vec)
    std::cout << x << ' ';
  std::cout << std::endl;
}
