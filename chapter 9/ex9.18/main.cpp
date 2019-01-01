#include <deque>
#include <iostream>

int main() {
    std::string str;
    std::deque<std::string> deq;
    while (std::cin >> str)
        deq.push_back(str);
    for (auto iter = deq.cbegin(); iter != deq.cend(); ++iter)
        std::cout << *iter << std::endl;
    return 0;
}