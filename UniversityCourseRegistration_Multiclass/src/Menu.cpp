#include "Menu.h"
#include "InputHelper.h"
#include "RegistrationException.h"
#include <iostream>
#include <limits>

using namespace std;

void studentMenu(UniversitySystem& system, const string& sid) {
    int choice = -1;
    do {
        cout << "\n===== STUDENT MENU =====\n"
             << "1. View Courses\n2. Register Course\n3. Drop Course\n"
             << "4. View My Schedule\n0. Logout\n";
        choice = readInt("Enter choice: ");
        try {
            string cid;
            switch (choice) {
                case 1: system.showCourses(); break;
                case 2:
                    system.showCourses();
                    cout << "Enter Course ID: "; cin >> cid;
                    system.registerCourse(sid,cid); break;
                case 3:
                    system.showSchedule(sid);
                    cout << "Enter Course ID: "; cin >> cid;
                    system.dropCourse(sid,cid); break;
                case 4: system.showSchedule(sid); break;
                case 0: cout << "Logging out...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << '\n';
        }
    } while (choice != 0);
}

void adminMenu(UniversitySystem& system) {
    int choice = -1;
    do {
        cout << "\n===== ADMIN MENU =====\n"
             << "1. View Courses\n2. Add Course\n3. Update Course\n"
             << "4. Delete Course\n5. View Students\n0. Logout\n";
        choice = readInt("Enter choice: ");
        try {
            string id, title;
            int credits, capacity;
            switch (choice) {
                case 1: system.showCourses(); break;
                case 2:
                    cout << "Course ID: "; cin >> id;
                    cout << "Course Title: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin,title);
                    credits = readInt("Credits: ");
                    capacity = readInt("Capacity: ");
                    system.addCourse(Course(id,title,credits,capacity)); break;
                case 3:
                    system.showCourses();
                    cout << "Course ID: "; cin >> id;
                    cout << "New Title: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin,title);
                    credits = readInt("New Credits: ");
                    capacity = readInt("New Capacity: ");
                    system.updateCourse(id,title,credits,capacity); break;
                case 4:
                    system.showCourses();
                    cout << "Course ID to delete: "; cin >> id;
                    system.deleteCourse(id); break;
                case 5: system.showStudents(); break;
                case 0: cout << "Logging out...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << '\n';
        }
    } while (choice != 0);
}
