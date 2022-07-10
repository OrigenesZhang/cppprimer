//
// Created by Bin Zhang on 11/7/22.
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

Bulk_quote::Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {
  std::cout << "Bulk_quote: copy constructor" << std::endl;
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &bq) {
  Disc_quote::operator=(bq);
  std::cout << "Bulk_quote: copy operator" << std::endl;
  return *this;
}

Bulk_quote::Bulk_quote(Bulk_quote &&bq) noexcept: Disc_quote(std::move(bq)) {
  std::cout << "Bulk_quote: move constructor" << std::endl;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&bq) noexcept {
  Disc_quote::operator=(std::move(bq));
  std::cout << "Bulk_quote: move operator" << std::endl;
  return *this;
}
