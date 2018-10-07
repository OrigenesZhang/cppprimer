#include <iostream>
#include <sstream>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main() {
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (getline(std::cin, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    return 0;
}