//
// Created by Bin Zhang on 11/7/22.
//

#include "Basket.h"

bool Basket::compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
  return lhs->isbn() < rhs->isbn();
}

void Basket::add_item(const Quote &sale) {
  items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote &&sale) {
  items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::total_receipt(std::ostream &os) const {
  double sum = 0;
  for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    sum += print_total(os, **iter, items.count(*iter));
  os << "Total Sale: " << sum << std::endl;
  return sum;
}
