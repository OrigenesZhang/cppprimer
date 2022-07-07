#include "Limit_quote.h"

int main() {
  Limit_quote lq("limit quote", 10.5, 5, 0.3);
  Quote &qr = lq;
  qr.debug();
}
