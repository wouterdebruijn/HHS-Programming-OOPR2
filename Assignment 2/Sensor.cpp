#include "Sensor.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Sensor::Sensor(int a,int b): x(a),y(b),geactiveerd(false) {}

void Sensor::activeer() {
    geactiveerd=true;
}

void Sensor::deactiveer() {
    geactiveerd=false;
}

bool Sensor::isGeactiveerd() const {
    return geactiveerd;
}

pair<int,int> Sensor::coordinaten() const {
     pair<int,int> temp;
     temp.first=x;
     temp.second=y;
     return temp;
 }

void Sensor::teken(QPaintDevice* tp) {
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

