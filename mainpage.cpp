#include "mainpage.h"
#include "ui_mainpage.h"

mainpage::mainpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainpage)
{
    ui->setupUi(this);
    this->setGeometry(QRect(400,250,1080,600));
    background = QPixmap(":/img/background2.png");
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //背景
    painter.drawPixmap(0,0,1080,600,background);
}



void mainpage::on_pushButton_4_clicked()
{
    this->close();

}


void mainpage::on_pushButton_1_clicked()
{
    game01page = new game01;
    game01page->show();
    game01page->setAttribute(Qt::WA_DeleteOnClose);
}


void mainpage::on_pushButton_2_clicked()
{
    game02page = new game02;
    game02page->show();
    game02page->setAttribute(Qt::WA_DeleteOnClose);
}


void mainpage::on_pushButton_3_clicked()
{
    game03page = new game03;
    game03page->show();
    game03page->setAttribute(Qt::WA_DeleteOnClose);
}

