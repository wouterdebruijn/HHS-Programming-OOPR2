#ifndef LOCK_H
#define LOCK_H

#include <string>

class Lock {
    public:
        virtual void unlock(const std::string key) = 0;
        virtual void lock() = 0;
        virtual bool isLocked() = 0;
};

#endif // LOCK_H
