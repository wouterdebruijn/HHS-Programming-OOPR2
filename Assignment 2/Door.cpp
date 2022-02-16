#include "Door.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Door::Door(int x, int y, unsigned int length) : x(x), y(y), length(length), status(false), lock(nullptr) {}
Door::Door(int x, int y, unsigned int length, Lock *lock) : x(x), y(y), length(length), status(false), lock(lock) {}

void Door::close() {
    if (this->lock != nullptr)
        this->lock->lock();
    status = false;
}

void Door::open() {
    // Open if we don't have a lock.
    if (this->lock == nullptr) {
        status = true;
        return;
    }

    // Check if lock is open, and open door.
    if (!this->lock->isLocked())
        status = true;
}

unsigned int Door::doorLength() {
    return this->length;
}

void Door::draw(QPaintDevice * tp) {
    QPainter p(tp);
    p.setBrush(Qt::SolidPattern);
    p.setBrush(Qt::black);

    QPen pen(Qt::black,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);

    if (isOpen())
        p.drawLine(x,y,x-length,y);
    else
        p.drawLine(x,y,x,y+length);
}

bool Door::isOpen() {
    return this->status;
}

Lock* Door::getLock() {
    return this->lock;
}
