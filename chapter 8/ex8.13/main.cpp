#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

bool valid(const std::string &nums) {
    if (nums.length() != 10)
        return false;
    for (auto it : nums)
        if (!isdigit(it))
            return false;
    return true;
}

std::string format(const std::string &nums) {
    return '+' + nums.substr(0, 2) + '-' + nums.substr(2, 6) + '-' + nums.substr(6, 10);
}

int main() {
    std::ifstream is("data.in");
    std::string line, word;
    std::vector<PersonInfo> people;
    while (getline(is, line)) {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    std::ofstream os("data.out", std::ofstream::app);
    for (const auto &entry : people) {
        std::ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
            os << entry.name << " " << formatted.str() << std::endl;
        else
            std::cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << std::endl;
    }
    os.close();
    return 0;
}