//
// Created by Bin Zhang on 7/7/22.
//

#ifndef EX15_16_LIMIT_QUOTE_H
#define EX15_16_LIMIT_QUOTE_H

#include "../ex15.15/Disc_quote.h"

class Limit_quote : public Disc_quote {
public:
  Limit_quote() = default;
  Limit_quote(const std::string &book, double price, size_t qty, double disc): Disc_quote(book, price, qty, disc) {}
  [[nodiscard]] double net_price(size_t) const override;
  void debug() const override;
};


#endif //EX15_16_LIMIT_QUOTE_H
