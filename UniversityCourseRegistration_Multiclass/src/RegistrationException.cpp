#include "RegistrationException.h"

RegistrationException::RegistrationException(const std::string& message)
    : std::runtime_error(message) {}
