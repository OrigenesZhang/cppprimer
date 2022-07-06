//
// Created by Bin Zhang on 6/7/22.
//

#ifndef EX15_11_BULK_QUOTE_H
#define EX15_11_BULK_QUOTE_H


#include <utility>
#include "Quote.h"

class Bulk_quote : public Quote {
public:
  Bulk_quote() = default;
  Bulk_quote(std::string bookNo, double price, size_t qty, double disc):
      Quote(std::move(bookNo), price), min_qty(qty), discount(disc) {}
  [[nodiscard]] double net_price(size_t) const override;
  void debug() const override;
private:
  size_t min_qty = 0;
  double discount = 0.0;
};


#endif //EX15_11_BULK_QUOTE_H
