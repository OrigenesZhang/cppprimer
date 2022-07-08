class Base {
public:
  void pub_mem() {}
protected:
  int prot_mem;
private:
  char priv_mem;
};

struct Pub_Derv : public Base {
  void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
  void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_public : public Pub_Derv {
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_private : public Priv_Derv {
  // void memfcn(Base &b) { b = *this; }
};

struct Derived_from_protected : public Prot_Derv {
  void memfcn(Base &b) { b = *this; }
};

int main() {
  Pub_Derv d;
  Base *p = &d;

  Derived_from_public dp;
  p = &dp;
}
