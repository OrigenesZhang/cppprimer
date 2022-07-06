//
// Created by Bin Zhang on 6/7/22.
//

#ifndef EX15_11_QUOTE_H
#define EX15_11_QUOTE_H


#include <string>
#include <utility>

class Quote {
public:
  Quote() = default;
  Quote(std::string bookNo, double sales_price): bookNo(std::move(bookNo)), price(sales_price) {}
  [[nodiscard]] std::string isbn() const { return bookNo; }
  [[nodiscard]] virtual double net_price(size_t n) const { return n * price; }
  virtual void debug() const;
  virtual ~Quote() = default;
private:
  std::string bookNo;
protected:
  double price = 0.0;
};


#endif //EX15_11_QUOTE_H
