#include <iostream>
#include <vector>

void print(const std::vector<int> &vec, std::vector<int>::iterator it) {
    if (it == vec.end()) return;
    std::cout << *it << ' ';
    print(vec, it + 1);
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    print(vec, vec.begin());
    return 0;
}