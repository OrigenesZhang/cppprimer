#include <iostream>

void print(const int *beg, const int *end) {
    while (beg != end) {
        std::cout << *beg++ << std::endl;
    }
}

void print(const int *arr, size_t size) {
    for (decltype(size) idx = 0; idx != size; ++idx) {
        std::cout << arr[idx] << std::endl;
    }
}

int main() {
    int i = 0, j[2] = {0, 1};
    print(&i, &i + 1);
    print(std::begin(j), std::end(j));
    print(&i, 1);
    print(j, 2);
    return 0;
}