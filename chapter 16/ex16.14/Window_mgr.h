//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_14_WINDOW_MGR_H
#define EX16_14_WINDOW_MGR_H


#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "Screen.h"

template <pos H, pos W>
class Window_mgr {
  friend class Screen<H, W>;

public:
  typedef typename std::vector<Screen<H, W>>::size_type screen_index;

  Window_mgr() = default;

  void clear(screen_index);
  void push_back(const Screen<H, W>&);
  void push_back(Screen<H, W>&&);

private:
  std::vector<Screen<H, W>> screens;
  void check(screen_index, const std::string &msg) const;
};

template <pos H, pos W>
inline void Window_mgr<H, W>::check(screen_index i, const std::string &msg) const {
  if (i >= screens.size())
    throw std::out_of_range(msg);
}

template <pos H, pos W>
void Window_mgr<H, W>::clear(screen_index i) {
  check(i, "screen_index out of range");
  screens[i].contents = std::string(H * W, ' ');
}

template <pos H, pos W>
inline void Window_mgr<H, W>::push_back(const Screen<H, W> &s) {
  screens.push_back(s);
}

template <pos H, pos W>
inline void Window_mgr<H, W>::push_back(Screen<H, W> &&s) {
  screens.push_back(std::move(s));
}

#endif //EX16_14_WINDOW_MGR_H
