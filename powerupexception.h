#ifndef POWERUPEXCEPTION_H
#define POWERUPEXCEPTION_H

#include <stdexcept>
#include <string>

class PowerUpException : public std::runtime_error {
public:
    explicit PowerUpException(const std::string& msg)
        : std::runtime_error(msg) {}
};

#endif // POWERUPEXCEPTION_H
