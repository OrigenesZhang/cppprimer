#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

struct ShorterString {
  bool operator()(const string &s1, const string &s2) const {
    return s1.size() < s2.size();
  }
};

class LongerOrEqual {
public:
  explicit LongerOrEqual(size_t sz): size(sz) {}
  bool operator()(const string &s) const {
    return s.size() >= size;
  }
private:
  size_t size;
};

struct PrintString {
  void operator()(const string &s) const {
    std::cout << s << " ";
  }
};

void elimDups(vector<string> &words) {
  std::sort(words.begin(), words.end());
  auto end_iter = std::unique(words.begin(), words.end());
  words.erase(end_iter, words.end());
}


string make_plural(size_t cnt, const string &word, const string &ending) {
  return cnt > 1 ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
  elimDups(words);
  std::stable_sort(words.begin(), words.end(), ShorterString());
  auto wc = std::find_if(words.begin(), words.end(), LongerOrEqual(sz));
  auto count = words.end() - wc;
  std::cout << count << " " << make_plural(count, "word", "s")
  << " of length " << sz << " or longer" << std::endl;
  std::for_each(wc, words.end(), PrintString());
  std::cout << std::endl;
}

int main() {
  vector<string> vec{"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle"};
  biggies(vec, 4);
}
