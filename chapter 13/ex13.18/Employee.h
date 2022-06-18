//
// Created by Bin Zhang on 19/6/22.
//

#ifndef EX13_18_EMPLOYEE_H
#define EX13_18_EMPLOYEE_H

#include <string>

class Employee {
public:
  Employee();
  explicit Employee(std::string);

  [[nodiscard]] int get_id() const {
    return id;
  }
private:
  std::string name;
  int id;
  static int counter;
};


#endif //EX13_18_EMPLOYEE_H
