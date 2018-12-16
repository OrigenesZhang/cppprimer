#include <iostream>
#include <vector>

// If the element is not found, the end iterator of the range is returned
std::vector<int>::iterator find(std::pair<std::vector<int>::iterator, std::vector<int>::iterator> range, int val) {
    auto beg = range.first, end = range.second;
    for (auto it = beg; it != end; ++it)
        if (*it == val)
            return it;
    return end;
}

int main() {
    return 0;
}