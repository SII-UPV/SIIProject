#ifndef GAMEPADDIALOG_H
#define GAMEPADDIALOG_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include "gamepad.h"

namespace Ui {
class GamepadDialog;
}

class GamepadDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit GamepadDialog(QWidget *parent = 0, Gamepad *_gamepad=0);
    ~GamepadDialog();


public slots:

    void Update();

private:
    QTimer* timer;
    Gamepad* gamepad;
    Ui::GamepadDialog *ui;
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // GAMEPADDIALOG_H
