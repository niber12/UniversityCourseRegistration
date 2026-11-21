#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <string>

class Registration {
private:
    std::string studentId;
    std::string courseId;
public:
    Registration(const std::string& studentId, const std::string& courseId);
    std::string getStudentId() const;
    std::string getCourseId() const;
};
#endif
