//
// Created by Bin Zhang on 11/7/22.
//

#ifndef EX15_27_QUOTE_H
#define EX15_27_QUOTE_H

#include <string>
#include <utility>
#include <iostream>

class Quote {
public:
  Quote() = default;
  Quote(std::string bookNo, double sales_price): bookNo(std::move(bookNo)), price(sales_price) {}
  Quote(const Quote&);
  Quote& operator=(const Quote&);
  Quote(Quote&&) noexcept;
  Quote& operator=(Quote&&) noexcept;
  [[nodiscard]] std::string isbn() const { return bookNo; }
  [[nodiscard]] virtual double net_price(size_t n) const { return n * price; }
  virtual void debug() const;
  virtual ~Quote() { std::cout << "Quote: destructor" << std::endl; }
private:
  std::string bookNo;
protected:
  double price = 0.0;
};

#endif //EX15_27_QUOTE_H
