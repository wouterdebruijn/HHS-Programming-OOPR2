#ifndef REVOLVINGDOOR_H
#define REVOLVINGDOOR_H

#include "Door.h"
#include <QPaintDevice>
#include "Lock.h"

class RevolvingDoor : public Door {
public:
    RevolvingDoor(int,int,unsigned int, bool, bool);
private:
    bool lefty;
    bool horizontal;

public:
    void draw(QPaintDevice *);
};

#endif // REVOLVINGDOOR_H
