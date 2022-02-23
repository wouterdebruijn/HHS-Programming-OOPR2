#include "Door.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Door::Door(int x, int y, unsigned int length) : x(x), y(y), length(length), status(false) {}

void Door::close() {
    for (auto const& lock : this->locks) {
        lock->lock();
    }

    status = false;
}

void Door::open() {
    bool openMe = true;

    for (auto const& lock : this->locks) {
        if (lock->isLocked())
            openMe = false;
    }

    status = openMe;
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

std::list<QLineLock*> Door::getLocks() {
    return this->locks;
}

void Door::addLock(QLineLock* lock) {
    this->locks.push_back(lock);
}
