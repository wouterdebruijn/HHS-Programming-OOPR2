#ifndef SLIDINGDOOR_H
#define SLIDINGDOOR_H

#include "Door.h"
#include "Sensor.h"
#include "Lock.h"

class SlidingDoor : public Door {
public:
    SlidingDoor(int, int, unsigned int, Sensor *);
    void draw(QPaintDevice *) override;
    void close() override;
private:
    Sensor *safetySensor;
};

#endif // SLIDINGDOOR_H
