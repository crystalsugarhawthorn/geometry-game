#ifndef GAME02_H
#define GAME02_H

#include <QWidget>
#include <qpainter.h>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include "square.h"

namespace Ui {
class game02;
}

class game02 : public QWidget
{
    Q_OBJECT

public:
    int SQU;
    int score = 0;
    float sunHP = 100;
    explicit game02(QWidget *parent = nullptr);
    ~game02();
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
    void squaremove();
    void endgame1();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_24_clicked();

private:
    Ui::game02 *ui;
    QTimer* timer1 ,* timer2,* timer3,* timer4,* timer5;
    QTime* timeRecord;
    int kingx = 480,kingy = 400;
    QPixmap drawsun,drawstarKing,
        drawstarKingL,drawstarKingR,
        drawstarKingD,kingattack,kingattack2,background;
    int king_pos;
    bool king_attack;
    square sq[1000];
    QRect sq_[1000];
};

#endif // GAME02_H
