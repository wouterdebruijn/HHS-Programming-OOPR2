#ifndef KEYLOCK_H
#define KEYLOCK_H

#include "Lock.h"
#include <string>

class KeyLock : public Lock<std::string> {
public:
    KeyLock(const std::string code);
    void unlock(const std::string key);
    void lock();
    bool isLocked();
private:
    bool locked;
    std::string code;
};

#endif // KEYLOCK_H
