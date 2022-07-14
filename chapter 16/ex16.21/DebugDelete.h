//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_21_DEBUGDELETE_H
#define EX16_21_DEBUGDELETE_H


#include <iostream>

class DebugDelete {
public:
  explicit DebugDelete(std::ostream &s = std::cerr): os(s) {}

  template <typename T>
  void operator()(T* p) const {
    os << "deleting unique_ptr" << std::endl;
    delete p;
  }

private:
  std::ostream &os;
};


#endif //EX16_21_DEBUGDELETE_H
