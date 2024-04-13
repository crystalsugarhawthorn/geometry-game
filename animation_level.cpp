#include "animation_level.h"
#include "ui_animation_level.h"


animation_level::animation_level(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::animation_level)
{
    ui->setupUi(this);
    this->setGeometry(QRect(300,300,1080,600));
    setWindowTitle("GEOMETRY GAME");
    timeCounter = 1;
    ui->groupBox->close();
}

animation_level::~animation_level()
{
    delete ui;
}

void animation_level::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    //背景
    QRect rect1(15,15,1050,570);
    painter.setPen(Qt::black);
    painter.setBrush(QColorConstants::Svg::blanchedalmond);
    painter.drawRect(rect1);


}

void animation_level::on_pushButton_clicked()
{
    QString textNormal;
    QFont font;
    switch (timeCounter) {
    case 1:
        textNormal = "这是一个" + QString('\n') + "充满几何体" + QString('\n') + "的世界";
        ui->label->setText(textNormal);
        timeCounter++;
        break;
    case 2:
        textNormal = "这些几何体" + QString('\n') + "特点各不相同";
        ui->label->setText(textNormal);
        timeCounter++;
        break;
    case 3:
        textNormal = "却都想" + QString('\n') + "夺走王国的太阳";
        ui->label->setText(textNormal);
        timeCounter++;
        break;
    case 4:
        textNormal = "你的任务……" + QString('\n') + "就是守护太阳";
        ui->label->setText(textNormal);
        timeCounter++;
        break;
    case 5:
        font.setPointSize(60);
        font.setFamily("华文隶书");
        ui->label->setFont(font);
        ui->label->setText("保卫你的王国");
        timeCounter++;
        break;
    case 6:
        ui->label->setWordWrap(false);
        QTimer *timer1 = new QTimer(this);
        connect(timer1,SIGNAL(timeout()),this,SLOT(closeLable()));
        timer1->start(25);
        ui->pushButton->close();
        timeCounter = -1;
    } 
}

void animation_level::closeLable(){
    static int timelength = 0;
    if(timelength <= 80){
        ui->label->setGeometry(ui->label->x()+5,ui->label->y(),ui->label->width()-10,ui->label->height());
        timelength++;
    }
    else if(timelength == 81){
        ui->groupBox->show();
    }
    else{
        timer1->stop();
        return;
    }
}

void animation_level::on_pushButton_8_clicked()
{
    this->close();
}


void animation_level::on_pushButton_2_clicked()
{
    game01page->show();
}

