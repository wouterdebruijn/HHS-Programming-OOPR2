#ifndef CODELOCK_H
#define CODELOCK_H

#include "Lock.h"

class CodeLock : public Lock<unsigned int> {
public:
    CodeLock(const unsigned int code);
    void lock();
    void unlock(const unsigned int code);
    bool isLocked();
private:
    unsigned int code;
    bool locked;
};

#endif // CODELOCK_H
