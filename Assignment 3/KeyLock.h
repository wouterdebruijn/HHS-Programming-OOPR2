#ifndef KEYLOCK_H
#define KEYLOCK_H

#include "QLineLock.h"

class KeyLock : public QLineLock {
public:
    KeyLock(const std::string code, QLineEdit* input);
    void unlock(const std::string key);
    void lock();
    bool isLocked();
private:
    bool locked;
    std::string code;
};

#endif // KEYLOCK_H
