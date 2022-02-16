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

    doors[0] = std::shared_ptr<SlidingDoor>(new SlidingDoor(503,250,80,s1.get()));
    doors[1] = std::shared_ptr<RevolvingDoor>(new RevolvingDoor(295, 290, 30, true, true));
    doors[2] = std::shared_ptr<RevolvingDoor>(new RevolvingDoor(248, 140, 40, false, false));

    doors[0]->addLock(new KeyLock("Hello World", ui->lineEdit0));
    doors[0]->addLock(new KeyLock("Hello World!", ui->lineEdit1));

    doors[1]->addLock(new CodeLock(420, ui->lineEdit1));
    doors[1]->addLock(new CodeLock(69, ui->lineEdit2));

    doors[2]->addLock(new CodeLock(42, ui->lineEdit2));
}

MainWindow::~MainWindow() {
    // No deletes are needed, we use shared_ptr which will auto-delete
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen;
    QImage image("/home/wouter/Documents/Projects/Git/wouterdebruijn/HHS-Programming-OOPR2/Assignment 3/gebouw.png");


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
        // Update the locks
        for (auto const& lock : doors[0]->getLocks()) {
                lock->unlock(lock->getUiInput()->text().toStdString());
        }

        doors[0]->open();
    }
    update();
}

void MainWindow::on_Button_Door1_clicked() {
    if (doors[1]->isOpen())
        doors[1]->close();
    else {
        // Update the locks
        for (auto const& lock : doors[1]->getLocks()) {
                lock->unlock(lock->getUiInput()->text().toStdString());
        }

        doors[1]->open();
    }
    update();
}

void MainWindow::on_Button_Door2_clicked() {
    if (doors[2]->isOpen())
        doors[2]->close();
    else {
        // Update the locks
        for (auto const& lock : doors[2]->getLocks()) {
                lock->unlock(lock->getUiInput()->text().toStdString());
        }

        doors[2]->open();
    }
    update();
}
