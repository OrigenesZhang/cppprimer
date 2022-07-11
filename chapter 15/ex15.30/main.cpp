#include <iostream>
#include "Basket.h"
#include "Quote.h"
#include "Bulk_quote.h"

int main() {
  Basket basket;
  for (size_t i = 0; i < 10; ++i)
    basket.add_item(Bulk_quote("bq1", 10.5, 10, 0.3));
  for (size_t i = 0; i < 5; ++i)
    basket.add_item(Bulk_quote("bq2", 20.5, 3, 0.5));
  for (size_t i = 0; i < 5; ++i)
    basket.add_item(Quote("quote", 15.5));
  basket.total_receipt(std::cout);
}
