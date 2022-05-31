#include <iostream>
#include <string>

using std::string;

void replace(string &s, const string &oldVal, const string &newVal) {
  if (oldVal.size() > s.size()) return;
  for (auto iter = s.begin(); iter <= s.end() - decltype(s.end() - s.begin())(oldVal.size()); ) {
    if (oldVal == string{iter, iter + decltype(s.end() - s.begin())(oldVal.size())}) {
      iter = s.erase(iter, iter + decltype(s.end() - s.begin())(oldVal.size()));
      iter = s.insert(iter, newVal.begin(), newVal.end());
      iter += decltype(s.end() - s.begin())(oldVal.size());
    } else ++iter;
  }
}

int main() {
  string s = "thr tho thru";
  replace(s, "tho", "though");
  replace(s, "thru", "through");
  std::cout << s << std::endl;
}
