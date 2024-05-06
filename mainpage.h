#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <qpainter.h>
#include "game01.h"

namespace Ui {
class mainpage;
}

class mainpage : public QWidget
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = nullptr);
    ~mainpage();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::mainpage *ui;
    game01 *game01page = new game01;
    int Sunshine, Crystal;
};

#endif // MAINPAGE_H
