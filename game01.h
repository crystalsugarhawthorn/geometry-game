#ifndef GAME01_H
#define GAME01_H

#include <QWidget>
#include <qpainter.h>

namespace Ui {
class game01;
}

class game01 : public QWidget
{
    Q_OBJECT

public:
    explicit game01(QWidget *parent = nullptr);
    ~game01();
     void paintEvent(QPaintEvent* event);

private:
    Ui::game01 *ui;
};

#endif // GAME01_H
