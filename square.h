#ifndef SQUARE_H
#define SQUARE_H
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QRect>


class square : public QWidget
{
    Q_OBJECT
public:
    int length = 50;
    int width = 50;
    int squX, squY, sunX = 470, sunY = 230;
    float HP = 100;
    int attack = 20;
    QTimer* timer;
    QRect squ;
    bool ismoving = false;
    bool isdefeated = false;
    square();
    square(int x, int y);
    square(const square & r);
    ~square();
    square& operator = (const square& s){
        this->squ = s.squ;
        this->squX = s.squX;
        this->squY = s.squY;
        return *this;
    };
    void squAttack();
public slots:
    void moving();
};

#endif // SQUARE_H
