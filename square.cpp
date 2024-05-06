#include "square.h"

square::square(){};
square::~square(){};
square::square(int x, int y) {
    squX = x,squY = y;
    squ = QRect(squX, squY, length, width);

}

void square::squAttack(){
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),SLOT(moving()));
    timer->start(50);
}

void square::moving(){
    if(HP <= 0){
        timer->stop();
    }
    else{
        if(squX > sunX + 20){
            squX--;
        }
        else if(squX < sunX - 20){
            squX++;
        }
        if(squY > sunY + 20){
            squY--;
        }
        else if(squY < sunY - 20){
            squY++;
        }
    }
}
