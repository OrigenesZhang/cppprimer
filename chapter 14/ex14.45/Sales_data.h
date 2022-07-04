//
// Created by Bin Zhang on 4/7/22.
//

#ifndef EX14_45_SALES_DATA_H
#define EX14_45_SALES_DATA_H

#include <string>
#include <utility>
#include <iostream>

class Sales_data {
public:
  friend std::istream& operator>>(std::istream&, Sales_data&);
  friend std::ostream& operator<<(std::ostream&, const Sales_data&);
  friend Sales_data operator+(const Sales_data&, const Sales_data&);
  friend Sales_data operator-(const Sales_data&, const Sales_data&);
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
  [[nodiscard]] inline double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
Sales_data operator-(const Sales_data&, const Sales_data&);

#endif //EX14_45_SALES_DATA_H
