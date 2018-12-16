#include <iostream>
#include <vector>

bool find(std::pair<std::vector<int>::iterator, std::vector<int>::iterator> range, int val) {
    auto beg = range.first, end = range.second;
    for (auto it = beg; it != end; ++it)
        if (*it == val)
            return true;
    return false;
}

int main() {
    return 0;
}