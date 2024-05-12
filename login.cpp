#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    this->setGeometry(QRect(200,200,1280,800));
    setWindowTitle("GEOMETRY GAME");
    background = QPixmap(":/img/background2.png");
}

login::~login()
{
    delete ui;
}

void login::paintEvent(QPaintEvent* event){
    QPainter painter(this);

    //游戏登录页背景
    painter.drawPixmap(0,0,1280,800,background);
}

void login::on_pushButton_2_clicked()
{
    //切换注册页
    signupPage = new signup;
    signupPage->show();
}

void sqlite_Init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if(!db.open())
    {
        qDebug()<<"open error";
    }
    //create excle
    QString createsql=QString("create table if not exists user(id integer primary key autoincrement,"
                                "username ntext unique not NULL,"
                                "password ntext not NULL)");
    QSqlQuery query;
    if(!query.exec(createsql)){
        qDebug()<<"table create error";
    }
    else{
        qDebug()<<"table create success";
    }
}

void login::on_pushButton_1_clicked()
{
    //lineEdit_1为账号框
    //lineEdit_2为密码框
    sqlite_Init();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString sql=QString("select * from user where username='%1' and password='%2'").arg(username).arg(password);
    //创建执行语句对象
    QSqlQuery query(sql);
    //判断执行结果
    if(!query.next())
    {
        qDebug()<<"Login error";
        QMessageBox::information(this,"登录认证","登录失败,账户或者密码错误");
    }
    else
    {
        qDebug()<<"Login success";
        QMessageBox::information(this,"登录认证","登录成功");
        //登录成功后可以跳转到其他页面
        animation_levelPage->show();
        this->close();
    }
}

