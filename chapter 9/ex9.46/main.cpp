#include <iostream>
#include <string>

using std::string;

string get_full_name(string name, const string &prefix, const string &suffix) {
  name.insert(0, prefix);
  name.insert(name.size(), suffix);
  return name;
}

int main() {
  std::cout << get_full_name("Origenes", "Mr. ", " II") << std::endl;
}
