#include "Registration.h"

Registration::Registration(const std::string& s, const std::string& c)
    : studentId(s), courseId(c) {}
std::string Registration::getStudentId() const { return studentId; }
std::string Registration::getCourseId() const { return courseId; }
