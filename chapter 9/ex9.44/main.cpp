#include <iostream>
#include <string>

using std::string;

void replace(string &s, const string &oldVal, const string &newVal) {
  if (oldVal.size() > s.size()) return;
  for (decltype(s.size()) i = 0; i <= s.size() - oldVal.size(); ) {
    if (oldVal == s.substr(i, oldVal.size())) {
      s.replace(i, oldVal.size(), newVal);
      i += newVal.size();
    } else ++i;
  }
}

int main() {
  string s = "thr tho thru";
  replace(s, "tho", "though");
  replace(s, "thru", "through");
  std::cout << s << std::endl;
}
