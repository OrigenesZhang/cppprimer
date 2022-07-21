#include <iostream>
#include <string>
#include <memory>

template <typename T, typename... Args>
auto my_make_shared(Args&&... args) -> std::shared_ptr<T> {
  return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
  auto int_ptr = my_make_shared<int>(1);
  std::cout << *int_ptr << std::endl;
  auto str_ptr = my_make_shared<std::string>(10, 'x');
  std::cout << *str_ptr << std::endl;
}
