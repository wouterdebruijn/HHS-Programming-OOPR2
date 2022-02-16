#ifndef HALLSENSOR_H
#define HALLSENSOR_H

#include "Sensor.h"

class HallSensor : public Sensor {
public:
    HallSensor(int,int);
    void teken(QPaintDevice *) override;
};

#endif // HALLSENSOR_H
