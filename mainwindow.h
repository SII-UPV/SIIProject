#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "gamepadinfo.h"
#include "gamepaddialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    GamepadInfo* gamepadInfo;
    Gamepad* gamepad;


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    checkActive(void);

private slots:
    void on_StartButton_clicked();

private:
    QTimer* time;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
