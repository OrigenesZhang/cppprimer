#include <iostream>
#include <list>
#include <vector>

int main() {
    std::list<int> list{1, 2, 3};
    std::vector<double> vec1(list.cbegin(), list.cend());
    for (auto it : vec1)
        std::cout << it << std::endl;
    std::vector<int> vi{1, 2, 3};
    std::vector<double> vec2(vi.cbegin(), vi.cend());
    for (auto it : vec2)
        std::cout << it << std::endl;
    return 0;
}