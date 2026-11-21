UNIVERSITY COURSE REGISTRATION SYSTEM

Student login accounts:
20253623  password 1234  (Hossain Md Niber)
20253633  password 2345  (Ahmed Md Miraj)
20253657  password 3456  (Gautam Dilip)
20253638  password 4567  (Thapa Rabin)

Admin login:
A1001  password admin123

Run on Windows with MinGW:
1. Open this folder in VS Code.
2. Terminal > New Terminal.
3. Run: mingw32-make
4. Run: .\app.exe

Alternative without Make:
g++ src/main.cpp src/User.cpp src/Student.cpp src/Admin.cpp src/Course.cpp src/Registration.cpp src/AuthSystem.cpp src/InputHelper.cpp src/RegistrationException.cpp src/UniversitySystem.cpp src/Menu.cpp -Iinclude -o app.exe
Then run: .\app.exe

Course and registration information is saved in courses.txt and registrations.txt.
