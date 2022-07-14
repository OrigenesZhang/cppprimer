//
// Created by Bin Zhang on 14/7/22.
//

#ifndef EX16_28_DELETE_H
#define EX16_28_DELETE_H


struct Delete {
  template<typename T>
  void operator()(T* p) const { delete p; }
};


#endif //EX16_28_DELETE_H
