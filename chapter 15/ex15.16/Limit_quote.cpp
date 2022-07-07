//
// Created by Bin Zhang on 7/7/22.
//

#include <iostream>
#include "Limit_quote.h"

double Limit_quote::net_price(size_t n) const {
  return n * price * (n < quantity ? 1 - discount : discount);
}

void Limit_quote::debug() const {
  Quote::debug();
  std::cout << "max_qty=" << quantity << '\n'
            << "discount=" << discount << '\n'
            << std::endl;
}
