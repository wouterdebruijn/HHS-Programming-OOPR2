#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLineEdit>
#include <QMessageBox>

#include "HallSensor.h"
#include "SlidingDoor.h"
#include "RevolvingDoor.h"

#include "KeyLock.h"
#include "CodeLock.h"
#include "RecognitionLock.h"
#include "PrinterQBox.h"
#include "LockException.h"
#include "CardLock.h"

#include <sstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    s1 = std::shared_ptr<HallSensor>(new HallSensor(515,160));

    doors[0] = std::shared_ptr<SlidingDoor>(new SlidingDoor(503,250,80,s1.get()));
    doors[1] = std::shared_ptr<RevolvingDoor>(new RevolvingDoor(295, 290, 30, true, true));
    doors[2] = std::shared_ptr<RevolvingDoor>(new RevolvingDoor(248, 140, 40, false, false));

    doors[1]->addLock(new CodeLock(420, ui->lineEdit1));
    doors[1]->addLock(new CodeLock(69, ui->lineEdit2));

    PrinterQBox *printer = new PrinterQBox(ui->textBrowser);
    RecognitionLock *nameLock = new RecognitionLock(printer, ui->lineEdit0);

    doors[2]->addLock(new CodeLock(42, ui->lineEdit1));

    nameLock->addToFolder("Wouter", true);
    nameLock->addToFolder("Tim", false);


    CardLock* frontDoorLock = new CardLock("FrontDoor", ui->lineEdit0);
    doors[0]->addLock(frontDoorLock);

    auto test = new IdCard("007", "Wouter", "Netherlands");
    frontDoorLock->addIdCard(test);

    // Refresh textbox on startup
    on_textBrowserRefresh_clicked();
}

MainWindow::~MainWindow() {
    // No deletes are needed, we use shared_ptr which will auto-delete
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen;
    QImage image("/home/wouter/Documents/Projects/Github/wouterdebruijn/HHS-Programming-OOPR2/Assignment 4/gebouw.png");


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
        try {
            for (auto const& lock : doors[0]->getLocks()) {
                    lock->unlock(lock->getUiInput()->text().toStdString());
            }

            doors[0]->open();
        } catch (LockException exception) {
            QMessageBox exceptionBox;

            std::stringstream outputStream;
            outputStream << "Exception on opening lock!\nCardId: " << exception.getIdCardID() << "\nLockLocation: " << exception.getLockLocation() << endl;
            exceptionBox.setText(QString::fromStdString(outputStream.str()));

            exceptionBox.exec();
        }
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

void MainWindow::addAuth(bool value) {
    for (auto const& lock : doors[2]->getLocks()) {
        auto* casted = dynamic_cast<RecognitionLock*>(lock);
        if (casted != nullptr)
            casted->addToFolder(ui->addAuthName->text().toStdString(), value);
    }
    // Refresh textbox;
    on_textBrowserRefresh_clicked();
}

void MainWindow::on_addAuthTrue_clicked() {
    addAuth(true);
}

void MainWindow::on_addAuthFalse_clicked() {
    addAuth(false);
}

void MainWindow::on_textBrowserRefresh_clicked() {
    for (auto const& door : doors) {
        for (auto const& lock : door->getLocks()) {
            auto* casted = dynamic_cast<RecognitionLock*>(lock);
            if (casted != nullptr)
                casted->showFolder();
        }
    }
}

void MainWindow::on_idCardTrue_clicked() {
    CardLock lock("", nullptr);

    // Create new card
    IdCard *card = new IdCard(ui->idCardId->text().toStdString(), ui->idCardName->text().toStdString(), ui->idCardAddress->text().toStdString());

    // Save card to "global" db
    lock.addIdCard(card);

    // Add authorization to front door lock(s)
    for (auto const& lock : doors[0]->getLocks()) {
        auto* casted = dynamic_cast<CardLock*>(lock);
        if (casted != nullptr)
            card->authorize(casted);
    }
}

void MainWindow::on_idCardFalse_clicked() {
    CardLock lock("", nullptr);

    // Remove card from db
    lock.removeIdCard(ui->idCardId->text().toStdString());

}
