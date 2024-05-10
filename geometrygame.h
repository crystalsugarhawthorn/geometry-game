#ifndef GEOMETRYGAME_H
#define GEOMETRYGAME_H

#include <QMainWindow>
#include <qpainter.h>
#include "login.h"
#include <qtimer.h>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QtMultimedia>

QT_BEGIN_NAMESPACE
namespace Ui {
class geometryGame;
}
QT_END_NAMESPACE

class geometryGame : public QMainWindow
{
    Q_OBJECT

public:
    QPixmap backgroung;
    geometryGame(QWidget *parent = nullptr);
    ~geometryGame();
    void paintEvent(QPaintEvent* event);

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::geometryGame *ui;
    login *loginPage = new login;

};
#endif // GEOMETRYGAME_H
