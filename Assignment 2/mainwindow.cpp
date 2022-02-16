#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLineEdit>

#include "HallSensor.h"
#include "SlidingDoor.h"
#include "RevolvingDoor.h"

#include "KeyLock.h"
#include "CodeLock.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    s1 = std::shared_ptr<HallSensor>(new HallSensor(515,160));

    doors[0] = std::shared_ptr<SlidingDoor>(new SlidingDoor(503,250,80,s1.get(), new KeyLock("HelloWorld")));
    doors[1] = std::shared_ptr<RevolvingDoor>(new RevolvingDoor(295, 290, 30, true, true, new CodeLock(420)));
    doors[2] = std::shared_ptr<RevolvingDoor>(new RevolvingDoor(248, 140, 40, false, false, new CodeLock(42)));
}

MainWindow::~MainWindow() {
    // No deletes are needed, we use shared_ptr which will auto-delete
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen;
    QImage image("/home/wouter/Documents/Projects/Git/wouterdebruijn/HHS-Programming-OOPR2/Assignment 2/gebouw.png");


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
    if (doors[0]->isOpen())
        doors[0]->close();
    else {
        // Update the lock if the door has one.
        if (doors[0]->getLock() != nullptr)
            doors[0]->getLock()->unlock(ui->lineEdit0->text().toStdString());

        doors[0]->open();
    }
    update();
}

void MainWindow::on_Button_Door1_clicked() {
    if (doors[1]->isOpen())
        doors[1]->close();
    else {
        // Update the lock if the door has one.
        if (doors[1]->getLock() != nullptr)
            doors[1]->getLock()->unlock(ui->lineEdit1->text().toStdString());

        doors[1]->open();
    }
    update();
}

void MainWindow::on_Button_Door2_clicked() {
    if (doors[2]->isOpen())
        doors[2]->close();
    else {
        // Update the lock if the door has one.
        if (doors[2]->getLock() != nullptr)
            doors[2]->getLock()->unlock(ui->lineEdit2->text().toStdString());

        doors[2]->open();
    }
    update();
}
