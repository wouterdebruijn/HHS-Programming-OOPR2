#ifndef QLINELOCK_H
#define QLINELOCK_H

#include <string>
#include "Lock.h"

class QLineEdit;

class QLineLock : public Lock {
public:
    QLineLock(QLineEdit*);
    virtual void unlock(const std::string key) = 0;
    virtual void lock() = 0;
    virtual bool isLocked() = 0;
    QLineEdit *getUiInput();
protected:
    QLineEdit *inputField;
};

#endif // QLINELOCK_H
