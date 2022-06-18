//
// Created by Bin Zhang on 19/6/22.
//

#include "Employee.h"

#include <utility>

Employee::Employee() {
  id = counter++;
}

Employee::Employee(std::string name) : name(std::move(name)) {
  id = counter++;
}
