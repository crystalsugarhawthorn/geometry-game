#ifndef ANIMATION_LEVEL_H
#define ANIMATION_LEVEL_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <qstring.h>
#include "mainpage.h"

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



private:
    Ui::animation_level *ui;
    mainpage* mp = new mainpage;
    QTimer *timer1;
    int timeCounter;
    QRect rect1;
};

#endif // ANIMATION_LEVEL_H
