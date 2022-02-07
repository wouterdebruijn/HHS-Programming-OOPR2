#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

#include "HallSensor.h"
#include "SlidingDoor.h"
#include "RevolvingDoor.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    s1 = std::shared_ptr<HallSensor>(new HallSensor(515,160));

    doors[0] = std::shared_ptr<SlidingDoor>(new SlidingDoor(503,250,80,s1.get()));
    doors[1] = std::shared_ptr<RevolvingDoor>(new RevolvingDoor(295, 290, 30, true, true));
    doors[2] = std::shared_ptr<RevolvingDoor>(new RevolvingDoor(248, 140, 40, false, false));
}

MainWindow::~MainWindow() {
    // No deletes are needed, we use shared_ptr which will auto-delete
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen;
    QImage image("/home/wouter/nas/School/HHS/Year 2/S3/OOPR2/Opdracht 1/gebouw.png");

    pen.setColor(Qt::green);
    pen.setWidth(4);
    painter.setPen(pen);
    painter.drawImage(10,10,image);

    s1->teken(this);

    unsigned int i;
    for (i = 0; i < sizeof(doors)/sizeof(doors[0]); i++) {
        doors[i]->draw(this);
    }
}

void MainWindow::on_sensor_act_clicked() {
    if(s1->isGeactiveerd())
         s1->deactiveer();
    else
         s1->activeer();
    update();
}

void MainWindow::on_Button_FrontDoor_clicked() {
    // Click event frontDoor
    if (doors[0]->isOpen())
        doors[0]->close();
    else
        doors[0]->open();
    update();
}

void MainWindow::doorClickEvent(unsigned int door) {
    if (doors[door]->isOpen())
        doors[door]->close();
    else
        doors[door]->open();
    update();
}

void MainWindow::on_Button_Door1_clicked() {
    doorClickEvent(1);
}

void MainWindow::on_Button_Door2_clicked() {
    doorClickEvent(2);
}
