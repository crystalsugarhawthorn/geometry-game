#ifndef ANIMATION_LEVEL_H
#define ANIMATION_LEVEL_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <qstring.h>
#include "game01.h"

namespace Ui {
class animation_level;
}

class animation_level : public QWidget
{
    Q_OBJECT

public:
    explicit animation_level(QWidget *parent = nullptr);
    ~animation_level();
    void paintEvent(QPaintEvent *event);

public slots:
    void closeLable();

private slots:
    void on_pushButton_clicked();
    //void clickTimes();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::animation_level *ui;
    QTimer *timer1;
    QTimer *timer2;
    int timeCounter;
    QRect rect1;
    game01 *game01page = new game01;
};

#endif // ANIMATION_LEVEL_H
