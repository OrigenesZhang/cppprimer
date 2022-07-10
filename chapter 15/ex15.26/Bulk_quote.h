//
// Created by Bin Zhang on 11/7/22.
//

#ifndef EX15_26_BULK_QUOTE_H
#define EX15_26_BULK_QUOTE_H


#include <string>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, size_t qty, double disc): Disc_quote(book, price, qty, disc) {}
  Bulk_quote(const Bulk_quote&);
  Bulk_quote& operator=(const Bulk_quote&);
  Bulk_quote(Bulk_quote&&) noexcept;
  Bulk_quote& operator=(Bulk_quote&&) noexcept;
  [[nodiscard]] double net_price(size_t) const override;
  void debug() const override;
  ~Bulk_quote() override { std::cout << "Bulk_quote: destructor" << std::endl; }
};

#endif //EX15_26_BULK_QUOTE_H
