#include <string>

class Sales_data {
public:
  Sales_data() = default;
  ~Sales_data() = default;
  Sales_data(int i): a(i) {}
  Sales_data(const Sales_data &rhs): a(rhs.a) {}
  Sales_data &operator=(const Sales_data &rhs){
    a = rhs.a;
    return *this;
  }

private:
  int a = 0;
};

class Token {
public:
  Token(): tok(INT), ival{0} {}
  Token(const Token &t): tok(t.tok) { copyUnion(t); }
  Token &operator=(const Token&);
  ~Token() {
    if (tok == STR) sval.~basic_string();
    if (tok == SAL) item.~Sales_data();
  }
  Token(Token&&) noexcept;
  Token &operator=(Token&&) noexcept;

  Token &operator=(const std::string&);
  Token &operator=(char);
  Token &operator=(int);
  Token &operator=(double);
  Token &operator=(const Sales_data&);

private:
  enum {INT, CHAR, DBL, STR, SAL} tok;
  union {
    char cval;
    int ival;
    double dval;
    std::string sval;
    Sales_data item;
  };
  void copyUnion(const Token&);
  void copyUnion(Token&&);
};

Token &Token::operator=(int i) {
  if (tok == STR) sval.~basic_string();
  if (tok == SAL) item.~Sales_data();
  ival = i;
  tok = INT;
  return *this;
}

Token &Token::operator=(char c) {
  if (tok == STR) sval.~basic_string();
  if (tok == SAL) item.~Sales_data();
  cval = c;
  tok = CHAR;
  return *this;
}

Token &Token::operator=(double d) {
  if (tok == STR) sval.~basic_string();
  if (tok == SAL) item.~Sales_data();
  dval = d;
  tok = DBL;
  return *this;
}

Token &Token::operator=(const std::string &s) {
  if (tok == SAL) item.~Sales_data();
  if (tok == STR)
    sval = s;
  else
    new(&sval) std::string(s);
  tok = STR;
  return *this;
}

void Token::copyUnion(const Token &t) {
  switch (t.tok) {
    case Token::INT:
      ival = t.ival;
      break;
    case Token::CHAR:
      cval = t.cval;
      break;
    case Token::DBL:
      dval = t.dval;
      break;
    case Token::STR:
      new(&sval) std::string(t.sval);
      break;
    case Token::SAL:
      new(&item) Sales_data(t.item);
      break;
  }
}

Token &Token::operator=(const Token &t) {
  if (tok == STR && t.tok != STR) sval.~basic_string();
  if (tok == SAL && t.tok != SAL) item.~Sales_data();
  if (tok == STR && t.tok == STR) sval = t.sval;
  else if (tok == SAL && t.tok == SAL) item = t.item;
  else copyUnion(t);
  tok = t.tok;
  return *this;
}

Token &Token::operator=(const Sales_data &i) {
  if (tok == STR) sval.~basic_string();
  if (tok == SAL)
    item = i;
  else
    new(&item) Sales_data(i);
  tok = SAL;
  return *this;
}

void Token::copyUnion(Token &&t) {
  switch (t.tok) {
    case Token::INT:
      ival = t.ival;
      break;
    case Token::CHAR:
      cval = t.cval;
      break;
    case Token::DBL:
      dval = t.dval;
      break;
    case Token::STR:
      sval = std::move(t.sval);
      break;
    case Token::SAL:
      item = std::move(t.item);
      break;
  }
}

Token::Token(Token &&t) noexcept {
  copyUnion(t);
  tok = t.tok;
}

Token &Token::operator=(Token &&t) noexcept {
  if (this != &t) {
    this->~Token();
    copyUnion(t);
    tok = t.tok;
  }
  return *this;
}

int main() {
}
