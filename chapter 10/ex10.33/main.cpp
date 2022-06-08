#include <fstream>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv) {
  if (argc != 4) return -1;
  std::ifstream fin(argv[1]);
  std::ofstream odd_out(argv[2]), even_out(argv[3]);
  std::istream_iterator<int> is(fin), eof;
  std::ostream_iterator<int> odd_os(odd_out, " "), even_os(even_out, "\n");
  std::for_each(is, eof, [&odd_os, &even_os](int i) {
    if (i % 2 == 1) *odd_os++ = i;
    else *even_os++ = i;
  });
}
