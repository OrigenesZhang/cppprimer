#include <iostream>

int odd[] = {1, 3, 5, 7, 9};
int even[] = {2, 4, 6, 8, 10};

decltype(odd) &arrPtr(int i) {
    return i % 2 ? odd : even;
}

int main() {
    std::cout << arrPtr(1)[2] << std::endl;
    std::cout << arrPtr(2)[2] << std::endl;
    return 0;
}