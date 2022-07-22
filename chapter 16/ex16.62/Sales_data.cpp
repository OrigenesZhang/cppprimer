//
// Created by Bin Zhang on 22/7/22.
//

#include "Sales_data.h"

inline double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

Sales_data::Sales_data(std::istream &is) {
  is >> *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::istream &operator>>(std::istream &is, Sales_data &item) {
  double price = 0.0;
  is >> item.bookNo >> item.units_sold >> price;
  if (is)
    item.revenue = price * item.units_sold;
  else
    item = Sales_data();
  return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price();
  return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}

Sales_data &Sales_data::operator-=(const Sales_data &rhs) {
  units_sold -= rhs.units_sold;
  revenue -= rhs.revenue;
  return *this;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data diff = lhs;
  diff -= rhs;
  return diff;
}

Sales_data &Sales_data::operator=(const std::string &isbn) {
  *this = Sales_data(isbn);
  return *this;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}
