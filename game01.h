#ifndef GAME01_H
#define GAME01_H

#include <QWidget>
#include <qpainter.h>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include "square.h"

namespace Ui {
class game01;
}

class game01 : public QWidget
{
    Q_OBJECT

public:
    int SQU;
    int sunshine, crystal;
    explicit game01(QWidget *parent = nullptr);
    ~game01();
    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void initTime();
    void updateTime();
    void pbStart_clicked();
    void spin();
    void on_pushButton_1_clicked();
    void attackfalse();
    void drawsquare();
    void on_pushButton_clicked();
    void squaremove();

private:
    Ui::game01 *ui;
    QTimer* timer1 ,* timer2,* timer3,* timer4,* timer5;
    QTime* timeRecord;
    int kingx = 480,kingy = 400;
    QPixmap drawsun,drawstarKing,
            drawstarKingL,drawstarKingR,
            drawstarKingD,kingattack,kingattack2;
    int king_pos;
    bool king_attack;
    square sq[1000];
    QRect sq_[1000];
};

#endif // GAME01_H
