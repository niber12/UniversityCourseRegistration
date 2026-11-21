#include "UniversitySystem.h"
#include "AuthSystem.h"
#include "Menu.h"
#include "InputHelper.h"
#include <iostream>

using namespace std;

int main() {
    try {
        UniversitySystem system;
        AuthSystem auth;

        cout << "========================================\n";
        cout << "     UNIVERSITY COURSE REGISTRATION\n";
        cout << "========================================\n";

        int choice = -1;
        do {
            cout << "\n===== MAIN MENU =====\n"
                 << "1. Student Login\n2. Admin Login\n0. Exit\n";
            choice = readInt("Enter choice: ");

            if (choice == 1) {
                string id, password;
                cout << "Enter Student ID: "; cin >> id;
                cout << "Enter Password: "; cin >> password;
                if (auth.studentLogin(id,password)) {
                    cout << "\nLogin successful!\n";
                    studentMenu(system,id);
                } else {
                    cout << "\nInvalid Student ID or password!\n";
                }
            } else if (choice == 2) {
                string id, password;
                cout << "Enter Admin ID: "; cin >> id;
                cout << "Enter Password: "; cin >> password;
                if (auth.adminLogin(id,password)) {
                    cout << "\nAdmin login successful!\n";
                    adminMenu(system);
                } else {
                    cout << "\nInvalid Admin ID or password!\n";
                }
            } else if (choice != 0) {
                cout << "Invalid choice!\n";
            }
        } while (choice != 0);

        cout << "\nThank you for using the system!\n";
    } catch (const exception& e) {
        cout << "System Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
