//
// Created by Bin Zhang on 11/7/22.
//

#include "Disc_quote.h"

Disc_quote &Disc_quote::operator=(const Disc_quote &dq) {
  Quote::operator=(dq);
  if (this != &dq) {
    quantity = dq.quantity;
    discount = dq.discount;
  }
  return *this;
}

Disc_quote::Disc_quote(Disc_quote &&dq) noexcept: Quote(std::move(dq)), quantity(dq.quantity), discount(dq.discount) {}

Disc_quote &Disc_quote::operator=(Disc_quote &&dq) noexcept {
  Quote::operator=(std::move(dq));
  if (this != &dq) {
    quantity = dq.quantity;
    discount = dq.discount;
  }
  return *this;
}
