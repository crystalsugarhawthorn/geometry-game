#include "signup.h"
#include "ui_signup.h"
#include "login.h"

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
    sqlite_Init();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_passwd->text();
    QString surepass = ui->lineEdit_surepasswd->text();
    //判断密码是否一致
    if(password == surepass)
    {
        QString sql=QString("insert into user(username,password) values('%1','%2');").arg(username).arg(password);
        //创建执行语句对象
        QSqlQuery query;
        //判断执行结果
        if(ui->checkBox->isChecked()){
            if(!query.exec(sql))
            {
                qDebug()<<"insert into error";
                QMessageBox::information(this,"注册认证","插入失败！");
            }
            else
            {

                    this->close();
                    qDebug()<<"insert into success";
                    QMessageBox::information(this,"注册认证","插入成功！");

            }
        }
    }
    else{
        QMessageBox::information(this,"注册认证","两次密码输入不一致");
    }

}
