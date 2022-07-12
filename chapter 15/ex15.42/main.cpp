#include <iostream>
#include "Query.h"
#include "TextQuery.h"

int main() {
  std::ifstream ifs("text.txt");
  TextQuery tQuery(ifs);
  Query q = Query("fiery") & Query("bird") | Query("wind");
  print(std::cout, q.eval(tQuery), 2, 5);
}
