#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& id, const std::string& name)
    : User(id, name) {}

void Admin::displayInfo() const {
    std::cout << "Administrator: " << getName() << '\n';
}
