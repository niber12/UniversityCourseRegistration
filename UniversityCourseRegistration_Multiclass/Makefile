CXX = g++
CXXFLAGS = -std=c++14 -Wall -Iinclude

SOURCES = src/main.cpp src/User.cpp src/Student.cpp src/Admin.cpp src/Course.cpp src/Registration.cpp src/AuthSystem.cpp src/InputHelper.cpp src/RegistrationException.cpp src/UniversitySystem.cpp src/Menu.cpp

app: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o app.exe

clean:
	del /Q app.exe 2>NUL
