#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"

class Admin : public User {
public:
    Admin(const std::string& id, const std::string& name);
    void displayInfo() const override;
};
#endif
