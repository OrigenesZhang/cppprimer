//
// Created by Bin Zhang on 11/7/22.
//

#ifndef EX15_30_BULK_QUOTE_H
#define EX15_30_BULK_QUOTE_H


#include <string>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  using Disc_quote::Disc_quote;
  Bulk_quote(const Bulk_quote&) = default;
  Bulk_quote& operator=(const Bulk_quote&) = default;
  Bulk_quote(Bulk_quote&&) noexcept;
  Bulk_quote& operator=(Bulk_quote&&) noexcept;
  [[nodiscard]] double net_price(size_t) const override;
  [[nodiscard]] Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
  [[nodiscard]] Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }
  void debug() const override;
  ~Bulk_quote() override = default;
};



#endif //EX15_30_BULK_QUOTE_H
