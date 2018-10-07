#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream is("data.in");
    std::string buff;
    std::vector<std::string> vec;
    while (getline(is, buff)) vec.push_back(buff);
    for (const auto &it : vec) {
        std::istringstream ss(it);
        while (ss >> buff) std::cout << buff << ' ';
    }
    std::cout << std::endl;
    return 0;
}