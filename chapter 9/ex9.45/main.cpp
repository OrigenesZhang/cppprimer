#include <iostream>
#include <string>

using std::string;

string get_full_name(string name, const string &prefix, const string &suffix) {
  name.insert(name.begin(), prefix.begin(), prefix.end());
  return name.append(suffix);
}

int main() {
  std::cout << get_full_name("Origenes", "Mr. ", " II") << std::endl;
}
