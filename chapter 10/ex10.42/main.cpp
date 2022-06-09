#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;

void elimDups(list<string> &words) {
  words.sort();
  words.unique();
}

int main() {
  list<string> words{"a", "b", "bb", "bbb", "bb", "a"};
  elimDups(words);
  for (const auto &x : words)
    std::cout << x << ' ';
  std::cout << std::endl;
}
