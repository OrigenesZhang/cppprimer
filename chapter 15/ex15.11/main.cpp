#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

int main() {
  Quote q("quote", 10.5);
  Bulk_quote bq("bulk quote", 10.5, 5, 0.3);
  q.debug();
  bq.debug();
}
