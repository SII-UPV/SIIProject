#ifndef CACERCADE_H
#define CACERCADE_H

#include <QMainWindow>

namespace Ui {
class CAcercaDe;
}

class CAcercaDe : public QMainWindow
{
    Q_OBJECT

public:
    explicit CAcercaDe(QWidget *parent = 0);
    ~CAcercaDe();

private:
    Ui::CAcercaDe *ui;
};

#endif // CACERCADE_H
