#include "Course.h"
#include <iostream>

Course::Course(const std::string& id, const std::string& t, int c, int cap)
    : courseId(id), title(t), credits(c), capacity(cap) {}
std::string Course::getCourseId() const { return courseId; }
std::string Course::getTitle() const { return title; }
int Course::getCredits() const { return credits; }
int Course::getCapacity() const { return capacity; }
void Course::setTitle(const std::string& t) { title = t; }
void Course::setCredits(int c) { credits = c; }
void Course::setCapacity(int c) { capacity = c; }

void Course::display(int enrolled) const {
    std::cout << courseId << " | " << title
              << " | Credits: " << credits
              << " | Registered: " << enrolled << "/" << capacity << '\n';
}
