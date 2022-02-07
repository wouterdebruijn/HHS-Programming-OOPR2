#include "Door.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Door::Door(int x, int y, unsigned int length) : x(x), y(y), length(length), status(false) {}

void Door::close() {
    status = false;
}

void Door::open() {
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
