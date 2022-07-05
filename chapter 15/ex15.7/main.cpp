#include <iostream>
#include "../ex15.5/Quote.h"
#include "Bulk_quote_limited.h"

double price_total(std::ostream &os, const Quote& item, size_t n) {
  double total_price = item.net_price(n);
  os << "ISBN: " << item.isbn() << "# sold: " << n << " total price: " << total_price << std::endl;
  return total_price;
}

int main() {
  Quote q("quote", 10.5);
  Bulk_quote_limited bql("bulk quote", 10.5, 5, 0.3);
  price_total(std::cout, q, 10);
  price_total(std::cout, bql, 10);
}
