#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <qpainter.h>
#include "game01.h"
#include "game02.h"
#include "game03.h"

namespace Ui {
class mainpage;
}

class mainpage : public QWidget
{
    Q_OBJECT

public:
    QPixmap background;
    explicit mainpage(QWidget *parent = nullptr);
    ~mainpage();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::mainpage *ui;
    game01 *game01page;
    game02 *game02page;
    game03 *game03page;
    int Sunshine, Crystal;
};

#endif // MAINPAGE_H
