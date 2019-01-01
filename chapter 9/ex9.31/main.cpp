#include <forward_list>
#include <iostream>
#include <list>

void go(std::list<int>& lst) {
    for (auto it = lst.begin(); it != lst.end(); ) {
        if (*it % 2) {
            it = lst.insert(it, *it);
            ++it, ++it;
        } else {
            it = lst.erase(it);
        }
    }
}

void go(std::forward_list<int> &flst) {
    for (auto pre = flst.before_begin(), cur = flst.begin(); cur != flst.end(); ) {
        if (*cur % 2) {
            pre = flst.insert_after(pre, *cur);
            ++pre, ++cur;
        } else {
            cur = flst.erase_after(pre);
        }
    }
}

int main() {
    std::list<int> lis = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::forward_list<int> flis(lis.begin(), lis.end());
    go(lis);
    for (auto val : lis)
        std::cout << val << ' ';
    std::cout << std::endl;
    go(flis);
    for (auto val : flis)
        std::cout << val << ' ';
    std::cout << std::endl;
    return 0;
}