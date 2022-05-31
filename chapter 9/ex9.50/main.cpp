#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int get_str_vec_sumi(const vector<string> &ivec) {
  int sum = 0;
  for (auto &s : ivec) sum += std::stoi(s);
  return sum;
}

double get_str_vec_sumd(const vector<string> &dvec) {
  double sum = 0;
  for (auto &s : dvec) sum += std::stod(s);
  return sum;
}

int main() {
  vector<string> ivec{"123", "0", "+55", "-3"};
  std::cout << get_str_vec_sumi(ivec) << std::endl;
  vector<string> dvec{"11", "3.14", "-.11", "2."};
  std::cout << get_str_vec_sumd(dvec) << std::endl;
}
