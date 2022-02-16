#include "KeyLock.h"

KeyLock::KeyLock(std::string code) : code(code), locked(false) {}

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
