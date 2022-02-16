#ifndef KEYLOCK_H
#define KEYLOCK_H

#include "Lock.h"

class KeyLock : public Lock {
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
