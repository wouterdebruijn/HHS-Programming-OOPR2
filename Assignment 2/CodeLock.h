#ifndef CODELOCK_H
#define CODELOCK_H

#include "Lock.h"

class CodeLock : public Lock {
public:
    CodeLock(const unsigned int code);
    void lock();
    void unlock(const std::string code);
    bool isLocked();
private:
    unsigned int code;
    bool locked;
};

#endif // CODELOCK_H
