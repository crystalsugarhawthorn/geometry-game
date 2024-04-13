#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    this->setGeometry(QRect(200,200,1280,800));
    setWindowTitle("GEOMETRY GAME");
}

login::~login()
{
    delete ui;
}

void login::paintEvent(QPaintEvent* event){
    QPainter painter(this);

    //游戏登录页背景
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::blanchedalmond);
    painter.drawRect(15,15,1250,770);
}

void login::on_pushButton_2_clicked()
{
    //切换注册页
    signupPage = new signup;
    signupPage->show();
}



void login::on_pushButton_1_clicked()
{
    //lineEdit_1为账号框
    //lineEdit_2为密码框
    this->close();
    animation_levelPage->show();
}

