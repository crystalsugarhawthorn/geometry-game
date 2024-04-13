#ifndef GEOMETRYGAME_H
#define GEOMETRYGAME_H

#include <QMainWindow>
#include <qpainter.h>
#include "login.h"
#include <qtimer.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class geometryGame;
}
QT_END_NAMESPACE

class geometryGame : public QMainWindow
{
    Q_OBJECT

public:
    geometryGame(QWidget *parent = nullptr);
    ~geometryGame();
    void paintEvent(QPaintEvent* event);
   // void Initline();


//public slots:
    //void line_update();


private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::geometryGame *ui;
    login *loginPage = new login;
    //QRect r1;
    //QTimer* timer;
};
#endif // GEOMETRYGAME_H
