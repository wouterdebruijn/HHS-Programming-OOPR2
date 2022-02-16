#ifndef LOCK_H
#define LOCK_H

template <class T>
class Lock {
    public:
        virtual void unlock(T key) = 0;
        virtual void lock() = 0;
        virtual bool isLocked() = 0;
};

#endif // LOCK_H
