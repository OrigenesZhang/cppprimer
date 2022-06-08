#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
  std::istream_iterator<int> is(std::cin), eof;
  std::vector<int> vec(is, eof);
  std::sort(vec.begin(), vec.end());
  std::ostream_iterator<int> os(std::cout, " ");
  std::copy(vec.cbegin(), vec.cend(), os);
}
