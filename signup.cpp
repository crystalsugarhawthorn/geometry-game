#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setGeometry(QRect(200,200,1280,800));
    setWindowTitle("GEOMETRY GAME");
}

signup::~signup()
{
    delete ui;
}

void signup::paintEvent(QPaintEvent* event){
    QPainter painter(this);

    //游戏注册页背景
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::blanchedalmond);
    painter.drawRect(15,15,1250,770);

}


void signup::on_pushButton_2_clicked()
{
    if(ui->checkBox->isChecked()){
        this->close();
    }
}

