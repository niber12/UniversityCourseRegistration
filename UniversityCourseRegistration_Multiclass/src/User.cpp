#include "User.h"

User::User(const std::string& i, const std::string& n) : id(i), name(n) {}
std::string User::getId() const { return id; }
std::string User::getName() const { return name; }
