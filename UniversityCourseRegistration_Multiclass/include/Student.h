#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"
#include <string>

class Student : public User {
private:
    std::string major;
public:
    Student(const std::string& id, const std::string& name,
            const std::string& major);
    void displayInfo() const override;
};
#endif
