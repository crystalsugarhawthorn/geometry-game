#include "square.h"

square::square(){};
square::~square(){};
square::square(int x, int y) {
    squX = x,squY = y;
    squ = QRect(squX, squY, length, width);
}
square::square(const square & r){
    squX = r.squX, squY = r.squY;
}


void square::squAttack(){
    timer = new QTimer;
    timer->start(100);
    connect(timer,SIGNAL(timeout()),SLOT(moving()));
}

void square::moving(){
    if(HP <= 0){
        squ = QRect();
        timer->stop();
    }
    else{
        if(squX > sunX + 100){
            squX-=2;
            squ.setLeft(squX);
            squ.setRight(squX + 50);
        }
        else if(squX < sunX - 50){
            squX+=2;
            squ.setLeft(squX);
            squ.setRight(squX + 50);
        }
        if(squY > sunY + 100){
            squY--;
            squ.setTop(squY);
            squ.setBottom(squY + 50);
        }
        else if(squY < sunY - 50){
            squY++;
            squ.setTop(squY);
            squ.setBottom(squY + 50);
        }
    }
}
