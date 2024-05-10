#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <qpainter.h>
#include "signup.h"
#include "animation_level.h"
/*
#include <QtSql/QSqlDatabase> //数据驱动
#include <QtSql/QSqlQuery> //数据库执行语句
#include <QMessageBox>//消息盒子
#include <QDebug>
#include <QtSql/QSql>
*/
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void paintEvent(QPaintEvent* event);
    QPixmap background;
    //void sqlite_Init();



private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::login *ui;
    signup *signupPage = new signup;
    animation_level *animation_levelPage = new animation_level;
};

#endif // LOGIN_H
