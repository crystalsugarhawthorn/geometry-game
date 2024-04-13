#include "game01.h"
#include "ui_game01.h"


game01::game01(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::game01)
{
    ui->setupUi(this);
    this->setGeometry(QRect(220,50,1280,960));
    setWindowTitle("关卡01");

}

game01::~game01()
{
    delete ui;
}

void game01::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    QRect rect1(15,15,1250,930);
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::darkgray);
    painter.drawRect(rect1);
}
