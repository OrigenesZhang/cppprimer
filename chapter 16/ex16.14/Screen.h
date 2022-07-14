//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_14_SCREEN_H
#define EX16_14_SCREEN_H


#include <iostream>
#include <string>

using pos = std::string::size_type;

template <pos H, pos W>
class Screen {
public:
  explicit Screen<H, W>(char c = ' ') : height(H), width(W), contents(height * width, c) {}

  friend std::istream& operator>>(std::istream& is, Screen<H, W>& s) {
    char c;
    is >> c;
    s.contents = std::string(H * W, c);
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s) {
    for (pos i = 0; i != H; ++i)
      os << s.contents.substr(i * W, W) << std::endl;
    return os;
  }

  Screen<H, W>& set(char);
  Screen<H, W>& set(pos, pos, char);
  Screen<H, W>& move(pos, pos);

  [[nodiscard]] pos size() const { return height * width; }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

template <pos H, pos W>
inline Screen<H, W>& Screen<H, W>::set(char c) {
  contents[cursor] = c;
  return *this;
}

template <pos H, pos W>
inline Screen<H, W>& Screen<H, W>::set(pos row, pos col, char c) {
  cursor = row * width + col;
  contents[row * width + col] = c;
  return *this;
}

template <pos H, pos W>
inline Screen<H, W>& Screen<H, W>::move(pos row, pos col) {
  cursor = row * width + col;
  return *this;
}


#endif //EX16_14_SCREEN_H
