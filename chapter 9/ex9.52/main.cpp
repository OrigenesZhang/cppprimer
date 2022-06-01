#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

int get_precedence(char op) {
  if (op == '(') return 0;
  if (op == '+' || op == '-') return 1;
  return 2;
}

void calc(stack<int> &nums, char op) {
  int b = nums.top(); nums.pop();
  int a = nums.top(); nums.pop();
  int ans;
  switch (op) {
    case '+':
      ans = a + b;
      break;
    case '-':
      ans = a - b;
      break;
    case '*':
      ans = a * b;
      break;
    case '/':
      ans = a / b;
      break;
    default:
      return;
  }
  nums.push(ans);
}

int main() {
  string s("10/2+(3-5*6+71)*2");
  stack<char> operations;
  stack<int> nums;
  for (string::size_type i = 0; i < s.size(); ++i) {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      if (operations.empty()) {
        operations.push(s[i]);
        continue;
      }
      char prev_operator = operations.top();
      int cur_precedence = get_precedence(s[i]), prev_precedence = get_precedence(prev_operator);
      while (!operations.empty() && prev_precedence >= cur_precedence) {
        operations.pop();
        calc(nums, prev_operator);
        if (!operations.empty()) {
          prev_operator = operations.top();
          prev_precedence = get_precedence(prev_operator);
        }
      }
      operations.push(s[i]);
    } else if (s[i] == '(') {
      operations.push(s[i]);
    } else if (s[i] == ')') {
      for (auto op = operations.top(); op != '('; op = operations.top()) {
        calc(nums, op);
        operations.pop();
      }
      operations.pop();
    } else {
      auto j = s.find_first_not_of("0123456789", i);
      if (j == string::npos) {
        nums.push(std::stoi(s.substr(i)));
        i = s.size() - 1;
      } else {
        nums.push(std::stoi(s.substr(i, j - i)));
        i = j - 1;
      }
    }
  }
  while (!operations.empty()) {
    auto op = operations.top();
    operations.pop();
    calc(nums, op);
  }
  std::cout << nums.top() << std::endl;
}
