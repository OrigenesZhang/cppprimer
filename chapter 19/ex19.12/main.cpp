#include <iostream>
#include <string>

class Screen {
public:
  Screen() = default;
  typedef std::string::size_type pos;
  Screen(pos h, pos w, pos i, char c) : height(h), weight(w), cursor(i), contents(h * w, c) {}
  char get_cursor() { return contents[cursor]; }
  static const pos Screen::*data() { return &Screen::cursor; }

private:
  std::string contents;
  pos cursor = 0;
  pos height = 0, weight = 0;
};

int main() {
  auto screen = Screen(3, 5, 4, 'a'), *pScreen = &screen;
  auto pData = Screen::data();
  std::cout << screen.*pData << std::endl;
  std::cout << pScreen->*pData << std::endl;
}
