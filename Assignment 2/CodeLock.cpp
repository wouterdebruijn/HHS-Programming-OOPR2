#include "CodeLock.h"

CodeLock::CodeLock(unsigned int code) : code(code), locked(false) {}

void CodeLock::lock() {
    this->locked = true;
}

bool CodeLock::isLocked() {
    return this->locked;
}

void CodeLock::unlock(unsigned int key) {
    if (key == code) {
        this->locked = false;
    }
}
