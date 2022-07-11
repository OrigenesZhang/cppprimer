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

Quote &Quote::operator=(const Quote &q) {
  if (this != &q) {
    bookNo = q.bookNo;
    price = q.price;
  }
  return *this;
}

Quote::Quote(Quote &&q) noexcept: bookNo(std::move(q.bookNo)), price(q.price) {}

Quote &Quote::operator=(Quote &&q) noexcept {
  if (this != &q) {
    bookNo = std::move(q.bookNo);
    price = q.price;
  }
  return *this;
}

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
  return ret;
}
