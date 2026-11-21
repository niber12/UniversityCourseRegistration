#include "AuthSystem.h"

bool AuthSystem::studentLogin(const std::string& id,
                              const std::string& password) const {
    return (id == "20253623" && password == "1234") ||
           (id == "20253633" && password == "2345") ||
           (id == "20253657" && password == "3456") ||
           (id == "20253638" && password == "4567");
}

bool AuthSystem::adminLogin(const std::string& id,
                            const std::string& password) const {
    return id == "A1001" && password == "admin123";
}
