#ifndef AUTH_SYSTEM_H
#define AUTH_SYSTEM_H
#include <string>

class AuthSystem {
public:
    bool studentLogin(const std::string& id, const std::string& password) const;
    bool adminLogin(const std::string& id, const std::string& password) const;
};
#endif
