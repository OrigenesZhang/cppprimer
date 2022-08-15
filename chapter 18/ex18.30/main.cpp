class Class {};

class Base : public Class {
public:
  Base() = default;
  explicit Base(int _b) : b(_b) {}
  Base(const Base &rhs) : b(rhs.b) {}

private:
  int b;
};

class D1 : virtual public Base {
public:
  D1() : Base() {}
  explicit D1(int b) : Base(b) {}
  D1(const D1 &d1) : Base(d1) {}
};

class D2 : virtual public Base {
public:
  D2() : Base() {}
  explicit D2(int b) : Base(b) {}
  D2(const D2 &d2) : Base(d2) {}
};

class MI : public D1, public D2 {
public:
  MI() : D1(), D2() {}
  explicit MI(int b) : Base(b), D1(b), D2(b) {}
  MI(const MI &mi) : Base(mi), D1(mi), D2(mi) {}
};

class Final : public MI, public Class {
public:
  Final() : Base(), MI(), Class() {}
  explicit Final(int b) : Base(b), MI(b) {}
  Final(const Final &f) : Base(f), MI(f) {}
};

int main() {
}
