#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{1, 2, 3};
    if (v1 == v2) std::cout << "v1 == v2" << std::endl;
    else std::cout << (v1 < v2 ? "v1 < v2" : "v2 < v1") << std::endl;
    return 0;
}