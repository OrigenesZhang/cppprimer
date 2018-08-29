#include <iostream>

int sum(const std::initializer_list<int> &lst) {
    int ret = 0;
    for (auto it : lst)
        ret += it;
    return ret;
}

int main() {
    std::initializer_list<int>lst = {1, 2, 3, 4};
    std::cout << sum(lst) << std::endl;
    return 0;
}