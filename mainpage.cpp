#include "mainpage.h"
#include "ui_mainpage.h"

mainpage::mainpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainpage)
{
    ui->setupUi(this);
     this->setGeometry(QRect(400,250,1080,600));
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //背景
    QRect rect1(15,15,1050,570);
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::blanchedalmond);
    painter.drawRect(rect1);
}



void mainpage::on_pushButton_4_clicked()
{
    this->close();

}


void mainpage::on_pushButton_1_clicked()
{
    game01page->show();
}

