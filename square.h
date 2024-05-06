#ifndef SQUARE_H
#define SQUARE_H
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QRect>


class square : public QWidget
{
    Q_OBJECT
private:
    int length = 50;
    int width = 50;
    int squX, squY, sunX, sunY;
    int HP = 100;
    int attack = 20;
    QTimer* timer;
public:
    QRect squ;
    square();
    square(int x, int y);
    ~square();
    void squAttack();
public slots:
    void moving();

};

#endif // SQUARE_H
