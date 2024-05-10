#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setGeometry(QRect(200,200,1280,800));
    setWindowTitle("GEOMETRY GAME");
    background = QPixmap(":/img/background2.png");
}

signup::~signup()
{
    delete ui;
}

void signup::paintEvent(QPaintEvent* event){
    QPainter painter(this);

    //游戏注册页背景
    painter.drawPixmap(0,0,1280,800,background);

}


void signup::on_pushButton_2_clicked()
{
    if(ui->checkBox->isChecked()){
        this->close();
    }
}

