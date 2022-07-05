#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

double price_total(std::ostream &os, const Quote& item, size_t n) {
  double total_price = item.net_price(n);
  os << "ISBN: " << item.isbn() << "# sold: " << n << " total price: " << total_price << std::endl;
  return total_price;
}

int main() {
  Quote q("quote", 10.5);
  Bulk_quote bq("bulk quote", 10.5, 5, 0.3);
  price_total(std::cout, q, 10);
  price_total(std::cout, bq, 10);
}
