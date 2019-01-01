#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> vec;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        vec.push_back(i);
    std::cout << vec.at(0) << std::endl;
    std::cout << vec[0] << std::endl;
    std::cout << vec.front() << std::endl;
    std::cout << *vec.begin() << std::endl;
    return 0;
}