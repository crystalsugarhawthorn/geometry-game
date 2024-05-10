#include "game02.h"
#include "ui_game02.h"

game02::game02(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::game02)
{
    ui->setupUi(this);
    this->setGeometry(QRect(400,250,1080,600));
    setWindowTitle("关卡01");
    ui->groupBox->close();
    ui->label_20->close();
    background = QPixmap(":/img/game_background.png");

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
    timer5 = new QTimer;
    connect(timer5,SIGNAL(timeout()),SLOT(endgame1()));
}

game02::~game02()
{
    delete ui;
}
 void game02::initTime(){
    timeRecord->setHMS(0, 0, 0); //时间复位为0
    ui->lcdNumber->display(timeRecord->toString("hh:mm:ss"));
}

void game02::updateTime(){
    *timeRecord = timeRecord->addSecs(1);
    ui->lcdNumber->display(timeRecord->toString("hh:mm:ss"));
}

void game02::pbStart_clicked(){
    timer1->start(1000);
    timer3->start(2000);
    timer5->start(200);
    ui->pushButton->close();
    ui->pushButton_1->show();
    ui->pushButton_2->show();
}

void game02::on_pushButton_1_clicked()
{
    if (QString::compare(ui->pushButton_1->styleSheet(),"border-image: url(:/img/pause.png)")){
        timer1->start(1000);
        timer2->start(10);
        timer3->start(2000);
        timer4->start(50);
        timer5->start(200);
        for(int i=0;i<SQU;i++){
            sq[i].timer->start(100);
        }
        ui->pushButton_1->setStyleSheet("border-image: url(:/img/pause.png)");
    }else{
        timer1->stop();
        timer2->stop();
        timer3->stop();
        timer4->stop();
        timer5->stop();
        for(int i=0;i<SQU;i++){
            sq[i].timer->stop();
        }
        ui->pushButton_1->setStyleSheet("border-image: url(:/img/play.png)");
    }
}

void game02::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::black);
    painter.drawRect(15,15,1050,570);
    painter.drawPixmap(20,20,1040,560,background);

    //Sun
    //太阳——光照攻击范围
    for(int i=0;i<SQU;i++){
        if((abs((sq[i].squX + 25)-520)<=100) && (abs((sq[i].squY + 25)-280)<=100)){
            sq[i].HP -= 0.3;
        }
    }
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
        for(int i = 0; i < SQU; i++){
            if((abs((sq[i].squX + 25)-(kingx + 50))<=100) && (abs((sq[i].squY + 25)-(kingy + 50))<=100)){
                sq[i].HP -= 2;
            }
        }
        QTimer::singleShot(200, this,SLOT(attackfalse()));

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
    if(sunHP > 0){
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

}

void game02::drawsquare(){
    int x1 = 790 + rand () % (1025 - 790 + 1);
    int x2 = 15 + rand () % (250 -15 + 1);
    int x = x1 < (1065 - x2) ? x1 : x2;
    int y = 100 + rand () % (500 - 100 + 1);
    while(SQU < 1000){
        square si(x, y);
        sq[SQU] = si;
        SQU++;
        break;
    }
    update();
}

void game02::squaremove(){
    for(int i = 0;i < SQU;i++){
        if(!sq[i].ismoving){
            sq[i].squAttack();
            sq[i].ismoving = true;
        }
    }
    update();
}

void game02::attackfalse(){
    king_attack = false;
}

void game02::spin(){
    //当界面初始化或者需要刷新时才会执行paintEvent
    update();
}

void game02::keyPressEvent(QKeyEvent *event)
{
    int step = 10;
    switch (event->key()) {
    case Qt::Key_W:
        kingy -= 12;
        king_pos = 1;
        break;
    case Qt::Key_S:
        kingy += 12;
        king_pos = 2;
        break;
    case Qt::Key_A:
        kingx -= 12;
        king_pos = 3;
        break;
    case Qt::Key_D:
        kingx += 12;
        king_pos = 4;
        break;
    case Qt::Key_J:
        king_attack = true;
    default:
        break;
    }
    update();
}

void game02::endgame1(){
    ui->label_18->setNum(score);
    if(sunHP <= 0){
        timer1->stop();
        timer2->stop();
        timer3->stop();
        timer4->stop();
        timer5->stop();
        for(int i=0;i<SQU;i++){
            sq[i].timer->stop();
        }
        ui->label_9->setNum(score);
        if(score <= 50){
            ui->label_20->setStyleSheet("border-image: url(:/img/stars_00.png)");
        }
        else if(score >100 && score <= 200){
            ui->label_20->setStyleSheet("border-image: url(:/img/stars_03.png)");
        }
        else if(score >200 && score <= 300){
            ui->label_20->setStyleSheet("border-image: url(:/img/stars_02.png)");
        }
        else if(score > 300){
            ui->label_20->setStyleSheet("border-image: url(:/img/stars_01.png)");
        }
        ui->groupBox->show();
        ui->label_20->show();
    }
    for(int i = 0; i < SQU; i++){
        if(sq[i].HP <= 0 && !sq[i].isdefeated){
            score += 25;
            sq[i].isdefeated = true;
        }
        if((abs((sq[i].squX + 25)-520)<=100) && (abs((sq[i].squY + 25)-280)<=100)){
            sunHP -= 1.2;
        }
    }
}

void game02::on_pushButton_5_clicked()
{
    this->close();
}


void game02::on_pushButton_18_clicked()
{
    ui->groupBox_2->show();
}


void game02::on_pushButton_24_clicked()
{
    ui->groupBox_2->close();
}
