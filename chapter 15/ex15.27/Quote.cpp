//
// Created by Bin Zhang on 11/7/22.
//

#include "Quote.h"
#include <iostream>

void Quote::debug() const {
  std::cout << "Data members of Quote:\n"
            << "bookNo=" << bookNo << '\n'
            << "price=" << price << '\n'
            << std::endl;
}

Quote::Quote(const Quote &q): bookNo(q.bookNo), price(q.price) {
  std::cout << "Quote: copy constructor" << std::endl;
}

Quote &Quote::operator=(const Quote &q) {
  if (this != &q) {
    bookNo = q.bookNo;
    price = q.price;
  }
  std::cout << "Quote: copy operator" << std::endl;
  return *this;
}

Quote::Quote(Quote &&q) noexcept: bookNo(std::move(q.bookNo)), price(q.price) {
  std::cout << "Quote: move constructor" << std::endl;
}

Quote &Quote::operator=(Quote &&q) noexcept {
  if (this != &q) {
    bookNo = std::move(q.bookNo);
    price = q.price;
  }
  std::cout << "Quote: move operator" << std::endl;
  return *this;
}
