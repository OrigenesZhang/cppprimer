#include <list>
#include <iostream>

int main() {
    std::string str;
    std::list<std::string> list;
    while (std::cin >> str)
        list.push_back(str);
    for (auto iter = list.cbegin(); iter != list.cend(); ++iter)
        std::cout << *iter << std::endl;
    return 0;
}