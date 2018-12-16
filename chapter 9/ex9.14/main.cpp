#include <iostream>
#include <list>
#include <vector>

int main() {
    char *ch1 = "Der";
    char *ch2 = "Die";
    char *ch3 = "Das";
    std::list<char*> list = {ch1, ch2, ch3};
    std::vector<std::string> vec;
    vec.assign(list.cbegin(), list.cend());
    for (const auto &it : vec)
        std::cout << it << std::endl;
    return 0;
}