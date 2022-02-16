#include "RevolvingDoor.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

RevolvingDoor::RevolvingDoor(int x,int y,unsigned int length, bool isHorizontal, bool isLefty): Door(x,y,length), horizontal(isHorizontal), lefty(isLefty) {}
RevolvingDoor::RevolvingDoor(int x,int y,unsigned int length, bool isHorizontal, bool isLefty, Lock* lock): Door(x,y,length, lock), horizontal(isHorizontal), lefty(isLefty) {}

void RevolvingDoor::draw(QPaintDevice *tp) {
    QPainter p(tp);
    p.setBrush(Qt::SolidPattern);
    p.setBrush(Qt::black);

    QPen pen(Qt::black,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);

    if (isOpen()) {
        if (horizontal) {
            if (lefty)
                p.drawLine(x,y,x,y-length);
            else
                p.drawLine(x,y,x,y+length);
        } else {
            if (lefty)
                p.drawLine(x,y,x-length,y);
            else
                p.drawLine(x,y,x+length,y);
        }
    } else {
        if (horizontal)
            p.drawLine(x,y,x-length,y);
        else
            p.drawLine(x,y,x,y-length);
    }

}
