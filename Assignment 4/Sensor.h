#ifndef SENSOR_H
#define SENSOR_H

#include <utility>

using namespace std;

class QPaintDevice;

class Sensor {
public:
    Sensor(int,int);
    virtual void teken(QPaintDevice*);
    void activeer();
    void deactiveer();
    bool isGeactiveerd()const;
    std::pair<int,int> coordinaten() const;

protected:
    int x,y;
    bool geactiveerd;
};

#endif // SENSOR_H
