#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Sensor.h"
#include "Door.h"

#include <memory>
#include <array>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
      ~MainWindow();

private slots:
    void on_sensor_act_clicked();
    void on_Button_FrontDoor_clicked();
    void on_Button_Door1_clicked();
    void on_Button_Door2_clicked();
    void on_addAuthTrue_clicked();
    void on_addAuthFalse_clicked();
    void on_textBrowserRefresh_clicked();
    void addAuth(bool);

private:
    std::shared_ptr<Ui::MainWindow> ui;
    std::shared_ptr<Sensor> s1;
    std::array<std::shared_ptr<Door>,3> doors = {};
};

#endif // MAINWINDOW_H
