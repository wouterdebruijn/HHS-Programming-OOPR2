#include "HallSensor.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

HallSensor::HallSensor(int x, int y) : Sensor(x,y) {

}

void HallSensor::teken(QPaintDevice* tp) {
    QPainter p(tp);
    QColor kleur;
    p.setBrush(Qt::SolidPattern);

    if(geactiveerd)
        kleur=Qt::blue;
    else
        kleur=Qt::yellow;

     p.setBrush(kleur);
     QPen pen(kleur,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
     p.setPen(pen);
     p.drawEllipse(x,y,20,20);
}
