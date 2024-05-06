#include "game01.h"
#include "ui_game01.h"


game01::game01(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::game01)
{
    ui->setupUi(this);
    this->setGeometry(QRect(400,250,1080,600));
    setWindowTitle("关卡01");

    ui->pushButton_1->close();
    ui->pushButton_2->close();

    timer1 = new QTimer;
    timeRecord = new QTime;
    ui->lcdNumber->setDigitCount(8);
    initTime();     //令LCD显示00:00:00
    //连接槽函数，将timer的timeout行为，连接到updateTime函数中
    connect(timer1, SIGNAL(timeout()), this, SLOT(updateTime()));
    //当点击(clicked)pbStart时，调用函数pbStart_clicked
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pbStart_clicked()));

    drawsun = QPixmap(":/img/sun-2081062_1920.png");
    drawstarKing = QPixmap(":/img/starKing-5943148.png");
    drawstarKingL = QPixmap(":/img/starKing-moveleft.png");
    drawstarKingR = QPixmap(":/img/starKing-moveright.png");
    drawstarKingD = QPixmap(":/img/starKing-movedown.png");
    kingattack = QPixmap(":/img/attack.png");
    kingattack = QPixmap(":/img/attack2.png");
    king_pos = 1;
    timer2 = new QTimer;
    timer2->start(10);
    connect(timer2,SIGNAL(timeout()),this,SLOT(spin()));

    SQU = 0;
    timer3 = new QTimer;
    connect(timer3,SIGNAL(timeout()),SLOT(drawsquare()));
    timer4 = new QTimer;
    timer4->start(50);
    connect(timer4,SIGNAL(timeout()),SLOT(squaremove()));
}

game01::~game01()
{
    delete ui;
}

void game01::initTime(){
    timeRecord->setHMS(0, 0, 0); //时间复位为0
    ui->lcdNumber->display(timeRecord->toString("hh:mm:ss"));
}

void game01::updateTime(){
    *timeRecord = timeRecord->addSecs(1);
    ui->lcdNumber->display(timeRecord->toString("hh:mm:ss"));
}

void game01::pbStart_clicked(){
    timer1->start(1000);
    ui->pushButton->close();
    ui->pushButton_1->show();
    ui->pushButton_2->show();
}

void game01::on_pushButton_1_clicked()
{
    if (QString::compare(ui->pushButton_1->styleSheet(),"border-image: url(:/img/music-1956799_1280(2).png)")){
        timer1->start(1000);
        ui->pushButton_1->setStyleSheet("border-image: url(:/img/music-1956799_1280(2).png)");
    }else{
        timer1->stop();
        ui->pushButton_1->setStyleSheet("border-image: url(:/img/music-1956799_1280(1).png)");
    }
}

void game01::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::black);
    painter.drawRect(15,15,1050,570);
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::blanchedalmond);
    painter.drawRect(20,20,1040,560);

    //Sun
    //太阳——光照攻击范围
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QColorConstants::Svg::black);
    painter.drawEllipse(420,180,200,200);
    painter.setBrush(QColorConstants::Svg::blue);
    painter.drawEllipse(450,210,140,140);

    //square
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::black);
    for(int i=0;i<SQU;i++){
        sq_[i] = sq[i].squ;
    }
    painter.drawRects(sq_,SQU);

    //角色——太阳、六芒星国王
    if(king_attack){
        painter.drawPixmap(kingx-113,kingy-113,300,300,kingattack);
        painter.drawPixmap(kingx-38,kingy-38,150,150,kingattack);
        painter.drawPixmap(kingx-13,kingy-13,100,100,kingattack2);
        QTimer::singleShot(250, this,SLOT(attackfalse()));
    }
    switch(king_pos){
    case 1:
        painter.drawPixmap(kingx,kingy,80,80,drawstarKing);
        break;
    case 2:
        painter.drawPixmap(kingx,kingy,80,80,drawstarKingD);
        break;
    case 3:
        painter.drawPixmap(kingx,kingy,80,80,drawstarKingL);
        break;
    case 4:
        painter.drawPixmap(kingx,kingy,80,80,drawstarKingR);
        break;
    }
    static int angle1 = 0;
    if(angle1++ == 360)
        angle1 = 0;
    //设定旋转中心点
    painter.translate(520,280);
    //旋转的角度
    painter.rotate(angle1);
    //恢复中心点
    painter.translate(-520,-280);
    //画图操作
    painter.drawPixmap(470,230,100,100,drawsun);
}


void game01::on_pushButton_clicked()
{
    timer3->start(10000);
}


void game01::drawsquare(){
    int x = 700+ rand () % (1000-700+1);
    int y = rand () % (600+1);
    while(SQU < 1000){
        square si(x, y);
        sq[SQU].squ = si.squ;
        SQU++;
        break;
    }
    update();
}

void game01::squaremove(){
    for(int i=0;i<SQU;i++){
        sq[i].squAttack();
    }
    update();
}

void game01::attackfalse(){
    king_attack = false;
}

void game01::spin(){
    //当界面初始化或者需要刷新时才会执行paintEvent
    update();
}

void game01::keyPressEvent(QKeyEvent *event)
{
    int step = 10;
    switch (event->key()) {
    case Qt::Key_W:
        kingy -= 10;
        king_pos = 1;
        break;
    case Qt::Key_S:
        kingy += 10;
        king_pos = 2;
        break;
    case Qt::Key_A:
        kingx -= 10;
        king_pos = 3;
        break;
    case Qt::Key_D:
        kingx += 10;
        king_pos = 4;
        break;
    case Qt::Key_J:
        king_attack = true;
    default:
        break;
    }
    update();
}




