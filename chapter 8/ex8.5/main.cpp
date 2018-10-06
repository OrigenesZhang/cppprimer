#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> read(std::string &name) {
    std::ifstream in(name);
    std::vector<std::string> ret;
    std::string now;
    while (in >> now) {
        ret.emplace_back(now);
    }
    in.close();
    return ret;
}

int main() {
    std::string name;
    while (std::cin >> name) {
        auto vec = read(name);
        for (const auto &it : vec)
            std::cout << it << std::endl;
        std::cout << std::endl;
    }
    return 0;
}