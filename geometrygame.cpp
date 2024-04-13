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
}

geometryGame::~geometryGame()
{
    delete ui;
}
void geometryGame::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //游戏开始页背景
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::blanchedalmond);
    painter.drawRect(15,15,1250,770);
   /* //划线动画
    painter.setPen(QColorConstants::Svg::darkgrey);
    painter.setBrush(QColorConstants::Svg::darkgrey);
    painter.drawRect(r1);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(line_update()));
    timer->start(1000);*/
}

/*void geometryGame::Initline(){
    QRect rect1(200,15,3,770);
    r1=rect1;
}

void geometryGame::line_update(){
    r1.moveRight(r1.x() + 10);
    update();
}*/

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

