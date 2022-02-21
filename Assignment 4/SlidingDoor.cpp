#include "SlidingDoor.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

SlidingDoor::SlidingDoor(int x, int y, unsigned int length, Sensor *sensor) : Door(x,y,length), safetySensor(sensor) {};

void SlidingDoor::draw(QPaintDevice *tp) {
    QPainter p(tp);
    p.setBrush(Qt::SolidPattern);
    p.setBrush(Qt::black);

    QPen pen(Qt::black,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);

    if (isOpen())
        p.drawLine(x,y,x,y+length);
    else
        p.drawLine(x,y,x,y-length);
}

void SlidingDoor::close() {
    if (!safetySensor->isGeactiveerd()) {

        for (auto const& lock : this->locks) {
            lock->lock();
        }

        status = false;
        safetySensor->activeer();
    }
}
