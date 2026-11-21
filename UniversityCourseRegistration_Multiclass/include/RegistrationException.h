#ifndef REGISTRATION_EXCEPTION_H
#define REGISTRATION_EXCEPTION_H
#include <stdexcept>
#include <string>

class RegistrationException : public std::runtime_error {
public:
    explicit RegistrationException(const std::string& message);
};
#endif
