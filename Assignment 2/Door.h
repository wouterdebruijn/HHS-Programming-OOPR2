#ifndef DOOR_H
#define DOOR_H

#include <QPaintDevice>
#include "Lock.h"

class Door {
public:
    Door(int, int, unsigned int);
    Door(int, int, unsigned int, Lock*);
    void open();
    virtual void close();
    virtual void draw(QPaintDevice *) = 0;
    bool isOpen();
    unsigned int doorLength();
    Lock* getLock();
protected:
    int x;
    int y;
    bool status;
    unsigned int length;
    Lock *lock;
};

#endif // DOOR_H
