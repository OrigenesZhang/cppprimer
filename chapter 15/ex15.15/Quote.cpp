//
// Created by Bin Zhang on 7/7/22.
//

#include "Quote.h"
#include <iostream>

void Quote::debug() const {
  std::cout << "Data members of Quote:\n"
            << "bookNo=" << bookNo << '\n'
            << "price=" << price << '\n'
            << std::endl;
}
