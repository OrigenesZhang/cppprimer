#include <iostream>
#include <list>
#include <sstream>
#include <vector>

int main() {
    std::list<int> list;
    std::vector<int> vector;
    std::cout << "Input list elements" << std::endl;
    std::string str;
    std::getline(std::cin, str);
    std::istringstream iss(str);
    int now;
    while (iss >> now)
        list.push_back(now);
    std::cout << "Input vector elements" << std::endl;
    std::getline(std::cin, str);
    iss.clear();
    iss.str(str);
    while (iss >> now)
        vector.push_back(now);
    auto lit = list.cbegin();
    auto vit = vector.cbegin();
    for (; lit != list.cend() && vit != vector.cend(); ++lit, ++vit) {
        if (*lit < *vit) {
            std::cout << "list < vector" << std::endl;
            return 0;
        } else if (*lit > *vit) {
            std::cout << "vector < list" << std::endl;
            return 0;
        }
    }
    if (list.size() == vector.size()) {
        std::cout << "list == vector" << std::endl;
    } else if (list.size() < vector.size()) {
        std::cout << "list < vector" << std::endl;
    } else {
        std::cout << "vector < list" << std::endl;
    }
    return 0;
}