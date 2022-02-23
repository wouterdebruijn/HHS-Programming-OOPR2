#include "CodeLock.h"

#include <sstream>

CodeLock::CodeLock(unsigned int code, QLineEdit* input) : QLineLock(input), code(code), locked(true) {}

void CodeLock::lock() {
    this->locked = true;
}

bool CodeLock::isLocked() {
    return this->locked;
}

void CodeLock::unlock(const std::string key) {
    std::stringstream intValue(key);
    unsigned int number = 0;
    intValue >> number;

    if (code == number) {
        this->locked = false;
    }
}
