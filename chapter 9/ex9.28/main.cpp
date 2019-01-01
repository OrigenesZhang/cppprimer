#include <forward_list>
#include <iostream>

void insert_after(std::forward_list<std::string> &flst, const std::string &s1, const std::string &s2) {
    auto pre = flst.before_begin();
    for (auto cur = flst.begin(); cur != flst.end(); ++cur) {
        if (*cur == s1) {
            flst.insert_after(cur, s2);
            return;
        }
        pre = cur;
    }
    flst.insert_after(pre, s2);
}

int main() {
    std::forward_list<std::string> flst{"a", "b", "cc", "d", "a"};
    std::string s1, s2;
    std::cin >> s1 >> s2;
    insert_after(flst, s1, s2);
    for (const auto &item : flst)
        std::cout << item << ' ';
    return 0;
}