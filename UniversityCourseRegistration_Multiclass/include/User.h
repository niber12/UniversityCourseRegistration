#ifndef USER_H
#define USER_H
#include <string>

class User {
private:
    std::string id;
    std::string name;
public:
    User(const std::string& id, const std::string& name);
    virtual ~User() = default;
    std::string getId() const;
    std::string getName() const;
    virtual void displayInfo() const = 0;
};
#endif
