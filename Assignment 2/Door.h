#ifndef DOOR_H
#define DOOR_H

#include <QPaintDevice>
#include "Lock.h"

class Door {
public:
    Door(int, int, unsigned int);
    void open();
    virtual void close();
    virtual void draw(QPaintDevice *) = 0;
    bool isOpen();
    unsigned int doorLength();
protected:
    int x;
    int y;
    bool status;
    unsigned int length;
    Lock *lock;
};

#endif // DOOR_H
