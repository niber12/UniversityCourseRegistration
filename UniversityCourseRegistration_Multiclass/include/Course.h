#ifndef COURSE_H
#define COURSE_H
#include <string>

class Course {
private:
    std::string courseId;
    std::string title;
    int credits;
    int capacity;
public:
    Course(const std::string& id, const std::string& title,
           int credits, int capacity);
    std::string getCourseId() const;
    std::string getTitle() const;
    int getCredits() const;
    int getCapacity() const;
    void setTitle(const std::string& title);
    void setCredits(int credits);
    void setCapacity(int capacity);
    void display(int enrolled) const;
};
#endif
