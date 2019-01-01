#include <deque>
#include <iostream>
#include <list>

int main() {
    std::list<int> list{1, 2, 3, 4, 5, 6, 8, 7, 1};
    std::deque<int> even, odd;
    for (int item : list) {
        if (item % 2 == 0) {
            even.push_back(item);
        } else {
            odd.push_back(item);
        }
    }
    for (int item : even)
        std::cout << item << ' ';
    std::cout << std::endl;
    for (int item : odd)
        std::cout << item << ' ';
    std::cout << std::endl;
    return 0;
}