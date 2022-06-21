#include <iostream>
#include <string>

class HasPtr {
public:
  friend void swap(HasPtr&, HasPtr&);
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
  HasPtr& operator=(const HasPtr &rhs) {
    if (this != &rhs) {
      delete ps;
      ps = new std::string(*rhs.ps);
      i = rhs.i;
      return *this;
    }
  }
  ~HasPtr() { delete ps; }
  void print() { std::cout << *ps << std::endl; }
private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  std::cout << "swap(HasPtr&, HasPtr&)" << std::endl;
}


int main() {
  HasPtr a("abc"), b("bcd");
  swap(a, b);
  a.print();
  b.print();
}
