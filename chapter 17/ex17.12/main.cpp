#include <iostream>
#include <string>
#include <bitset>

template <size_t> class QuizAnswer;
template <size_t N> std::ostream& operator<<(std::ostream&, const QuizAnswer<N>&);

template <size_t N>
class QuizAnswer {
  friend std::ostream& operator<< <N>(std::ostream&, const QuizAnswer<N>&);

public:
  QuizAnswer() = default;
  explicit QuizAnswer(const std::string &s): answers(s) {}

  void update(size_t qn, bool val) { answers.set(qn, val); }

private:
  std::bitset<N> answers;
};

template <size_t N>
std::ostream &operator<<(std::ostream &os, const QuizAnswer<N> &qa) {
  os << qa.answers;
  return os;
}

int main() {
  std::string s = "101110";
  QuizAnswer<10> quizAnswer(s);
  quizAnswer.update(1, false);
  quizAnswer.update(9, true);
  std::cout << quizAnswer << std::endl;
}
