#include <iostream>
#include <fstream>
#include <string>

using std::string;

int main() {
  std::ifstream ifs("../input.data");
  if (!ifs) return -1;
  string best;
  for (string now; ifs >> now;) {
    if (now.size() > best.size()
        && now.find_first_not_of("aceimnorsuvwxz") == string::npos) {
      best = now;
    }
  }
  std::cout << best << std::endl;
}
