#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<char> vec{'o', 'r', 'i', 'g', 'e', 'n', 'e', 's'};
  string s(vec.cbegin(), vec.cend());
  cout << s << endl;
}