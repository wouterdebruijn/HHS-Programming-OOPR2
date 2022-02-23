#include "KeyLock.h"

KeyLock::KeyLock(std::string code, QLineEdit* input) : QLineLock(input), code(code), locked(true) {}

void KeyLock::lock() {
    this->locked = true;
}

bool KeyLock::isLocked() {
    return this->locked;
}

void KeyLock::unlock(std::string key) {
    if (this->code.compare(key) == 0) {
        this->locked = false;
    }
}
