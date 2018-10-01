#include <iostream>

class Person;

std::istream &read(std::istream &, Person &);

class Person {
    friend std::istream &read(std::istream &, Person &);

    friend std::ostream &print(std::ostream &, const Person &);

private:
    std::string name;
    std::string address;
public:
    Person() = default;

    Person(const std::string &s1, const std::string &s2) : name(s1), address(s2) {}

    explicit Person(std::istream &in) {
        read(in, *this);
    }

    std::string getName() const;

    std::string getAddress() const;
};

std::string Person::getName() const {
    return name;
}

std::string Person::getAddress() const {
    return address;
}

std::istream &read(std::istream &in, Person &person) {
    in >> person.name >> person.address;
    return in;
}

std::ostream &print(std::ostream &out, const Person &person) {
    out << person.name << ' ' << person.address;
    return out;
}

int main() {
    return 0;
}