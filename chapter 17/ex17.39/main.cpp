#include <iostream>
#include <string>
#include <fstream>

using std::fstream;

int main() {
  fstream inOut("copyOut", fstream::ate | fstream::in | fstream::out);
  if (!inOut) {
    std::cerr << "Unable to open file!" << std::endl;
    return EXIT_FAILURE;
  }
  auto end_mark = inOut.tellg();
  inOut.seekg(0, fstream::beg);
  size_t cnt = 0;
  std::string line;
  while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
    cnt += line.size() + 1;
    auto mark = inOut.tellg();
    inOut.seekp(0, fstream::end);
    inOut << cnt;
    if (mark != end_mark) inOut << " ";
    inOut.seekg(mark);
  }
  inOut.seekp(0, fstream::end);
  inOut << '\n';
}
