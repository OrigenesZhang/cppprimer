#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1, vec2;
    int cur;
    while (std::cin >> cur && cur != -1)
        vec1.push_back(cur);
    while (std::cin >> cur && cur != -1)
        vec2.push_back(cur);
    if (vec1.size() > vec2.size()) std::swap(vec1, vec2);
    // when the shorter vector is empty, it is considered as a prefix of the other
    for (decltype(vec1.size()) idx = 0; idx != vec1.size(); ++idx) {
        if (vec1[idx] != vec2[idx]) {
            std::cout << "Not a prefix" << std::endl;
            return 0;
        }
    }
    std::cout << "A prefix" << std::endl;
    return 0;
}