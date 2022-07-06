//
// Created by Bin Zhang on 6/7/22.
//

#include "Bulk_quote.h"
#include <iostream>

double Bulk_quote::net_price(size_t n) const {
  if (n >= min_qty)
    return n * (1 - discount) * price;
  else
    return Quote::net_price(n);
}

void Bulk_quote::debug() const {
  std::cout << "Data members of Quote:\n"
            << "bookNo=" << isbn() << '\n'
            << "price=" << price << '\n'
            << "min_qty=" << min_qty << '\n'
            << "discount=" << discount << '\n'
            << std::endl;
}
