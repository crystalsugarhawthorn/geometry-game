#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <qpainter.h>

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    QPixmap background;
    explicit signup(QWidget *parent = nullptr);
    ~signup();
    void paintEvent(QPaintEvent* event);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
