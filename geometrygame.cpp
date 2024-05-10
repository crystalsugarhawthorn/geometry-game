#include "geometrygame.h"
#include "./ui_geometrygame.h"
#include "login.h"
geometryGame::geometryGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::geometryGame)
{
    ui->setupUi(this);
    this->setGeometry(QRect(200,200,1280,800));
    setWindowTitle("GEOMETRY GAME");
    backgroung = QPixmap(":/img/background2.png");
}
geometryGame::~geometryGame()
{
    delete ui;
}
void geometryGame::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //游戏开始页背景
    painter.drawPixmap(0,0,1280,800,backgroung);
}

void geometryGame::on_pushButton_1_clicked()
{
    //进入游戏，关闭初始页，打开登录页
    this->close();
    loginPage = new login;
    loginPage->show();
}


void geometryGame::on_pushButton_2_clicked()
{
    //退出游戏，关闭初始页
    this->close();
}

