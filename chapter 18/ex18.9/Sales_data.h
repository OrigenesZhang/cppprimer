//
// Created by Bin Zhang on 7/8/22.
//

#ifndef EX18_9_SALES_DATA_H
#define EX18_9_SALES_DATA_H


#include <stdexcept>
#include <string>
#include <utility>
#include <iostream>

class Sales_data {
  friend std::hash<Sales_data>;
  friend std::istream& operator>>(std::istream&, Sales_data&);
  friend std::ostream& operator<<(std::ostream&, const Sales_data&);
  friend Sales_data operator+(const Sales_data&, const Sales_data&);
  friend Sales_data operator-(const Sales_data&, const Sales_data&);
  friend bool operator==(const Sales_data&, const Sales_data&);

public:
  Sales_data(std::string s, unsigned n, double p): bookNo(std::move(s)), units_sold(n), revenue(n * p) {}
  Sales_data(): Sales_data("", 0, 0.0f) {}
  explicit Sales_data(std::string s): Sales_data(std::move(s), 0, 0.0f) {}
  explicit Sales_data(std::istream&);
  Sales_data& operator+=(const Sales_data&);
  Sales_data& operator-=(const Sales_data&);
  Sales_data& operator=(const std::string&);
  [[nodiscard]] std::string isbn() const { return bookNo; }
  explicit operator std::string() const { return bookNo; }
  explicit operator double() const { return avg_price(); }

private:
  [[nodiscard]] double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
Sales_data operator-(const Sales_data&, const Sales_data&);
bool operator==(const Sales_data&, const Sales_data&);

namespace std {
  template<>
  struct hash<Sales_data> {
    typedef size_t result_type;
    typedef Sales_data argument_type;
    size_t operator()(const Sales_data &s) const {
      return hash<std::string>()(s.bookNo) ^
             hash<unsigned>()(s.units_sold) ^
             hash<double>()(s.revenue);
    }
  };
}

class out_of_stock: public std::runtime_error {
public:
  explicit out_of_stock(const std::string &s): std::runtime_error(s) {}
};

class isbn_mismatch: public std::logic_error {
public:
  explicit isbn_mismatch(const std::string &s): std::logic_error(s) {}
  isbn_mismatch(const std::string &s, std::string lhs, std::string rhs):
    std::logic_error(s), left(std::move(lhs)), right(std::move(rhs)) {}

private:
  const std::string left, right;
};


#endif //EX18_9_SALES_DATA_H
