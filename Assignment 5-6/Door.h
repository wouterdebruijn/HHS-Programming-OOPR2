#ifndef DOOR_H
#define DOOR_H

#include <QPaintDevice>
#include "QLineLock.h"
#include <list>

class Door {
public:
    Door(int, int, unsigned int);
    void open();
    virtual void close();
    virtual void draw(QPaintDevice *) = 0;
    bool isOpen();
    unsigned int doorLength();
    std::list<QLineLock*> getLocks();
    void addLock(QLineLock*);
protected:
    int x;
    int y;
    bool status;
    unsigned int length;
    std::list<QLineLock*> locks;
};

#endif // DOOR_H
