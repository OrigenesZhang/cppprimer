#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> forward_list{1, 2, 3, 4, 4, 5, 5, 8};
    for (auto prev = forward_list.before_begin(), now = forward_list.before_begin(); now != forward_list.end(); ) {
        if (*now % 2)
            now = forward_list.erase_after(prev);
        else {
            prev = now;
            ++now;
        }
    }
    for (auto val : forward_list)
        std::cout << val << ' ';
    return 0;
}