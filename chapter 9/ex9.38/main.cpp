#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    for (std::vector<int>::size_type ix = 0; ix < 16; ix++) {
        vec.push_back(ix);
        std::cout << ix << ' ' << vec.size() << ' ' << vec.capacity() << std::endl;
    }
    vec.reserve(17);
    for (std::vector<int>::size_type ix = 16; ix < 18; ix++) {
        vec.push_back(ix);
        std::cout << ix << ' ' << vec.size() << ' ' << vec.capacity() << std::endl;
    }
    return 0;
}