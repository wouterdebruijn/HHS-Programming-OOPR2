#ifndef CODELOCK_H
#define CODELOCK_H

#include "QLineLock.h"

class CodeLock : public QLineLock {
public:
    CodeLock(const unsigned int code, QLineEdit* input);
    void lock();
    void unlock(const std::string code);
    bool isLocked();
private:
    unsigned int code;
    bool locked;
};

#endif // CODELOCK_H
