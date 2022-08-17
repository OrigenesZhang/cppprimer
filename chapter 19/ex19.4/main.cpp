#include <iostream>
#include <stdexcept>

class A {
public:
  virtual ~A() {}
};

class B : public A {
public:
  virtual ~B() {}
};

class C : public B {
public:
  virtual ~C() {}
};

class D : public B, public A {
public:
  virtual ~D() {}
};

int main() {
  C c;
  A &ra = c;
  try {
    C &rc = dynamic_cast<C&>(ra);
    std::cout << "Succeed!" << std::endl;
  } catch (std::bad_cast &e) {
    std::cout << "Failed: " << e.what() << std::endl;
  }
}
