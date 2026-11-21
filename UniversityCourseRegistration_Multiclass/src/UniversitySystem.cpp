#include "UniversitySystem.h"
#include "RegistrationException.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

Course* UniversitySystem::findCourse(const string& id) {
    for (auto& course : courses)
        if (course.getCourseId() == id) return &course;
    return nullptr;
}

bool UniversitySystem::studentExists(const string& id) const {
    for (const auto& student : students)
        if (student.getId() == id) return true;
    return false;
}

int UniversitySystem::registeredCount(const string& id) const {
    int count = 0;
    for (const auto& r : registrations)
        if (r.getCourseId() == id) ++count;
    return count;
}

void UniversitySystem::saveCourses() const {
    ofstream file("courses.txt");
    if (!file) throw RegistrationException("Cannot save courses.txt");
    for (const auto& c : courses)
        file << c.getCourseId() << '|' << c.getTitle() << '|'
             << c.getCredits() << '|' << c.getCapacity() << '\n';
}

void UniversitySystem::loadCourses() {
    ifstream file("courses.txt");
    if (!file) return;
    vector<Course> loaded;
    string line;
    while (getline(file, line)) {
        string id, title, creditText, capacityText;
        stringstream row(line);
        if (getline(row,id,'|') && getline(row,title,'|') &&
            getline(row,creditText,'|') && getline(row,capacityText)) {
            try {
                int credits = stoi(creditText);
                int capacity = stoi(capacityText);
                if (!id.empty() && !title.empty() && credits > 0 && capacity > 0)
                    loaded.emplace_back(id,title,credits,capacity);
            } catch (...) {}
        }
    }
    if (!loaded.empty()) courses = loaded;
}

void UniversitySystem::saveRegistrations() const {
    ofstream file("registrations.txt");
    if (!file) throw RegistrationException("Cannot save registrations.txt");
    for (const auto& r : registrations)
        file << r.getStudentId() << '|' << r.getCourseId() << '\n';
}

void UniversitySystem::loadRegistrations() {
    ifstream file("registrations.txt");
    string line;
    while (getline(file, line)) {
        string sid, cid;
        stringstream row(line);
        if (getline(row,sid,'|') && getline(row,cid) &&
            studentExists(sid) && findCourse(cid))
            registrations.emplace_back(sid,cid);
    }
}

UniversitySystem::UniversitySystem() {
    students.emplace_back("20253623","Hossain Md Niber","Intelligence Computing");
    students.emplace_back("20253633","Ahmed Md Miraj","Intelligence Computing");
    students.emplace_back("20253657","Gautam Dilip","Intelligence Computing");
    students.emplace_back("20253638","Thapa Rabin","Intelligence Computing");

    courses.emplace_back("WP2002","Web Programming 2",3,30);
    courses.emplace_back("OOP2002","Object Oriented Programming 2",3,25);
    courses.emplace_back("DS004","Data Structures",3,20);
    courses.emplace_back("LA001","Linear Algebra",3,35);

    loadCourses();
    loadRegistrations();
}

void UniversitySystem::showCourses() const {
    cout << "\n===== AVAILABLE COURSES =====\n";
    if (courses.empty()) cout << "No courses available.\n";
    for (const auto& c : courses)
        c.display(registeredCount(c.getCourseId()));
}

void UniversitySystem::showStudents() const {
    cout << "\n===== STUDENTS =====\n";
    for (const auto& s : students) s.displayInfo();
}

void UniversitySystem::registerCourse(const string& sid, const string& cid) {
    if (!studentExists(sid)) throw RegistrationException("Student not found!");
    Course* course = findCourse(cid);
    if (!course) throw RegistrationException("Course not found!");
    for (const auto& r : registrations)
        if (r.getStudentId() == sid && r.getCourseId() == cid)
            throw RegistrationException("Already registered!");
    if (registeredCount(cid) >= course->getCapacity())
        throw RegistrationException("Course is full!");
    registrations.emplace_back(sid,cid);
    saveRegistrations();
    cout << "Registration successful!\n";
}

void UniversitySystem::dropCourse(const string& sid, const string& cid) {
    auto it = find_if(registrations.begin(), registrations.end(),
        [&](const Registration& r) {
            return r.getStudentId() == sid && r.getCourseId() == cid;
        });
    if (it == registrations.end())
        throw RegistrationException("Registration not found!");
    registrations.erase(it);
    saveRegistrations();
    cout << "Course dropped successfully!\n";
}

void UniversitySystem::showSchedule(const string& sid) const {
    cout << "\n===== MY SCHEDULE =====\n";
    bool found = false;
    for (const auto& r : registrations) {
        if (r.getStudentId() == sid) {
            for (const auto& c : courses) {
                if (c.getCourseId() == r.getCourseId()) {
                    c.display(registeredCount(c.getCourseId()));
                    found = true;
                }
            }
        }
    }
    if (!found) cout << "No registered courses.\n";
}

void UniversitySystem::addCourse(const Course& course) {
    if (course.getCourseId().empty() || course.getTitle().empty() ||
        course.getCredits() < 1 || course.getCredits() > 6 ||
        course.getCapacity() < 1)
        throw RegistrationException("Invalid course data!");
    if (findCourse(course.getCourseId()))
        throw RegistrationException("Course already exists!");
    courses.push_back(course);
    saveCourses();
    cout << "Course added successfully!\n";
}

void UniversitySystem::updateCourse(const string& id, const string& title,
                                    int credits, int capacity) {
    Course* course = findCourse(id);
    if (!course) throw RegistrationException("Course not found!");
    if (title.empty() || credits < 1 || credits > 6 ||
        capacity < registeredCount(id) || capacity < 1)
        throw RegistrationException("Invalid course information!");
    course->setTitle(title);
    course->setCredits(credits);
    course->setCapacity(capacity);
    saveCourses();
    cout << "Course updated successfully!\n";
}

void UniversitySystem::deleteCourse(const string& id) {
    if (!findCourse(id)) throw RegistrationException("Course not found!");
    if (registeredCount(id) > 0)
        throw RegistrationException("Students are registered. Drop them first!");
    courses.erase(remove_if(courses.begin(), courses.end(),
        [&](const Course& c) { return c.getCourseId() == id; }), courses.end());
    saveCourses();
    cout << "Course deleted successfully!\n";
}
