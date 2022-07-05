//
// Created by Bin Zhang on 5/7/22.
//

#ifndef EX15_7_BULK_QUOTE_LIMITED_H
#define EX15_7_BULK_QUOTE_LIMITED_H

#include "../ex15.5/Quote.h"

class Bulk_quote_limited : public Quote {
public:
  Bulk_quote_limited() = default;
  Bulk_quote_limited(std::string bookNo, double price, size_t qty, double disc):
  Quote(std::move(bookNo), price), max_qty(qty), discount(disc) {}
  [[nodiscard]] double net_price(size_t) const override;
private:
  size_t max_qty = 0;
  double discount = 0.0;
};


#endif //EX15_7_BULK_QUOTE_LIMITED_H
