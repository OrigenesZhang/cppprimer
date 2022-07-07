//
// Created by Bin Zhang on 7/7/22.
//

#ifndef EX15_15_BULK_QUOTE_H
#define EX15_15_BULK_QUOTE_H


#include <string>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, size_t qty, double disc): Disc_quote(book, price, qty, disc) {}
  [[nodiscard]] double net_price(size_t) const override;
  void debug() const override;
};


#endif //EX15_15_BULK_QUOTE_H
