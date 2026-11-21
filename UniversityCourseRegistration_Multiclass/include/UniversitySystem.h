#ifndef UNIVERSITY_SYSTEM_H
#define UNIVERSITY_SYSTEM_H
#include "Course.h"
#include "Student.h"
#include "Registration.h"
#include <vector>
#include <string>

class UniversitySystem {
private:
    std::vector<Course> courses;
    std::vector<Student> students;
    std::vector<Registration> registrations;

    Course* findCourse(const std::string& id);
    bool studentExists(const std::string& id) const;
    int registeredCount(const std::string& courseId) const;
    void saveCourses() const;
    void loadCourses();
    void saveRegistrations() const;
    void loadRegistrations();

public:
    UniversitySystem();
    void showCourses() const;
    void showStudents() const;
    void registerCourse(const std::string& studentId, const std::string& courseId);
    void dropCourse(const std::string& studentId, const std::string& courseId);
    void showSchedule(const std::string& studentId) const;
    void addCourse(const Course& course);
    void updateCourse(const std::string& id, const std::string& title,
                      int credits, int capacity);
    void deleteCourse(const std::string& id);
};
#endif
