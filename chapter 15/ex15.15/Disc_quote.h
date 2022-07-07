//
// Created by Bin Zhang on 7/7/22.
//

#ifndef EX15_15_DISC_QUOTE_H
#define EX15_15_DISC_QUOTE_H


#include <string>
#include "Quote.h"

class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const std::string& book, double price, size_t qty, double disc):
    Quote(book, price), quantity(qty), discount(disc) {}
  [[nodiscard]] double net_price(size_t) const override = 0;
protected:
  size_t quantity = 0;
  double discount = 0;
};


#endif //EX15_15_DISC_QUOTE_H
