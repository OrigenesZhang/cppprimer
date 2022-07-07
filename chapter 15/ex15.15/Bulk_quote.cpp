//
// Created by Bin Zhang on 7/7/22.
//

#include "Bulk_quote.h"
#include <iostream>

double Bulk_quote::net_price(size_t n) const {
  if (n >= quantity)
    return n * (1 - discount) * price;
  else
    return n * price;
}

void Bulk_quote::debug() const {
  Disc_quote::debug();
  std::cout << "min_qty=" << quantity << '\n'
            << "discount=" << discount << '\n'
            << std::endl;
}
