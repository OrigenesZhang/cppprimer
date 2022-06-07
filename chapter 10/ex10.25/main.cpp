#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using std::vector;
using std::string;
using std::placeholders::_1;

void elemDups(vector<string> &vec) {
  std::sort(vec.begin(), vec.end());
  auto end_iter = std::unique(vec.begin(), vec.end());
  vec.erase(end_iter, vec.end());
}

bool check_size(const string &s, string::size_type sz) {
  return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
  elemDups(words);
  auto end_iter = std::partition(words.begin(), words.end(), std::bind(check_size, _1, sz));
  std::for_each(words.begin(), end_iter, [](const string &s) {
    std::cout << s << ' ';
  });
}

int main() {
  vector<string> vec{"aaa", "aa", "aaaa", "bbb", "bb", "b", "1123"};
  biggies(vec, 3);
  std::cout << std::endl;
}
