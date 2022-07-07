#include "Bulk_quote.h"

int main() {
  Bulk_quote bq("bulk quote", 10.5, 5, 0.3);
  Quote &qr = bq;
  qr.debug();
}
