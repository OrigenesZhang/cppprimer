#include <iostream>
#include <string>
#include <vector>

struct Base1 {
  void print(int) const {
    std::cout << "Base1::print(int)" << std::endl;
  }
protected:
  int ival;
  double dval;
  char cval;
private:
  int *id;
};

struct Base2 {
  void print(double) const {
    std::cout << "Base2::print(double)" << std::endl;
  }
protected:
  double fval;
private:
  double dval;
};

struct Derived : public Base1 {
  void print(std::string) const {
    std::cout << "Derived::print(std::string)" << std::endl;
  }
protected:
  std::string sval;
  double dval;
};

struct MI : public Derived, public Base2 {
  void print(std::vector<double>) {
    std::cout << "MI::print(std::vector<double>)" << std::endl;
  }
  void print(int x) {
    std::cout << "MI::print(int)" << std::endl;
    Base1::print(x);
  }
protected:
  int *ival;
  std::vector<double> dvec;
};

int main() {
  MI mi;
  mi.print(42);
}
