//
// Created by Bin Zhang on 11/7/22.
//

#ifndef EX15_30_QUOTE_H
#define EX15_30_QUOTE_H

#include <string>
#include <utility>
#include <iostream>

class Quote {
public:
  Quote() = default;
  Quote(std::string bookNo, double sales_price): bookNo(std::move(bookNo)), price(sales_price) {}
  Quote(const Quote&) = default;
  Quote& operator=(const Quote&);
  Quote(Quote&&) noexcept;
  Quote& operator=(Quote&&) noexcept;
  [[nodiscard]] std::string isbn() const { return bookNo; }
  [[nodiscard]] virtual double net_price(size_t n) const { return n * price; }
  [[nodiscard]] virtual Quote* clone() const & { return new Quote(*this); }
  [[nodiscard]] virtual Quote* clone() && { return new Quote(std::move(*this)); }
  virtual void debug() const;
  virtual ~Quote() = default;
private:
  std::string bookNo;
protected:
  double price = 0.0;
};

double print_total(std::ostream&, const Quote&, size_t);

#endif //EX15_30_QUOTE_H
