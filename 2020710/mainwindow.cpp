#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"enemy.h"
#include"spotbutton.h"
#include"main.cpp"
#include<QTimer>
#include<QPainter>
#include<QPixmap>
#include<QLabel>
#include<QDebug>

int death=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,500);
    this->setWindowIcon(QIcon(":/images/icon_gold.png"));
    this->setWindowTitle("2020.7.10");

    label->setText("hp:"+QString::number(hp)+"  "+"money："+QString::number(money));
    label->setGeometry(300,70,250,30);
    label->setStyleSheet("QLabel{border:2px solid rgb(200, 200, 200);}");
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    label->setPalette(pe);
    QFont ft;
    ft.setPointSize(15);
    label->setFont(ft);

    btn1->setParent(this);btn2->setParent(this);btn3->setParent(this);
    btn4->setParent(this);btn5->setParent(this);btn6->setParent(this);
    btn7->setParent(this);btn8->setParent(this);btn9->setParent(this);
    btn1->move(250,320);btn2->move(350,320);btn3->move(450,320);
    btn4->move(350,230);btn5->move(450,230);btn6->move(550,230);
    btn7->move(700,230);btn8->move(310,130);btn9->move(260,175);
    btn1->smove(250,320);btn2->smove(350,320);btn3->smove(450,320);
    btn4->smove(350,230);btn5->smove(450,230);btn6->smove(550,230);
    btn7->smove(700,230);btn8->smove(310,130);btn9->smove(260,175);

    spotbutton * tower1 = new  spotbutton(":/images/1.png");
    tower1->setParent(this);
    spotbutton * tower2 = new  spotbutton(":/images/2.png");
    tower2->setParent(this);
    spotbutton * tower3 = new  spotbutton(":/images/3.png");
    tower3->setParent(this);
    spotbutton * tower4 = new  spotbutton(":/images/4.png");
    tower4->setParent(this);
    tower1->move(0,20);tower2->move(0,120);
    tower3->move(0,220);tower4->move(0,320);


    spotbutton *del=new spotbutton(this);
    del->setParent(this);
    del->setText("删除");
    del->setGeometry(5,420,60,35);

    spotbutton *promote=new spotbutton(this);
    promote->setParent(this);
    promote->setText("升级");
    promote->setGeometry(70,420,60,35);

    spotbutton *pause=new spotbutton(this);
    pause->setParent(this);
    pause->setText("暂停");
    pause->setGeometry(5,460,60,35);

    spotbutton *goOn=new spotbutton(this);
    goOn->setParent(this);
    goOn->setText("继续");
    goOn->setGeometry(70,460,60,35);

    connect(promote,&QPushButton::clicked,[=](){
        flag=6;
    });

    connect(tower1,&QPushButton::clicked,[=](){
        flag=1;
    });

    connect(tower2,&QPushButton::clicked,[=](){
        flag=2;
    });
    connect(tower3,&QPushButton::clicked,[=](){
        flag=3;
    });
    connect(tower4,&QPushButton::clicked,[=](){
        flag=4;
    });
    connect(del,&QPushButton::clicked,[=](){
        flag=5;
    });
    connect(btn1,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn1);
            flag=0;
        }
    });
    connect(btn2,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn2);
            flag=0;
        }
    });
    connect(btn3,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn3);
            flag=0;
        }
    });
    connect(btn4,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn4);
            flag=0;
        }
    });
    connect(btn5,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn5);
            flag=0;
        }
    });
    connect(btn6,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn6);
            flag=0;
        }
    });
    connect(btn7,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn7);
            flag=0;
        }
    });
    connect(btn8,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn8);
            flag=0;
        }
    });
    connect(btn9,&QPushButton::clicked,[=](){
        if(flag!=0)
        {
            change(btn9);
            flag=0;
        }
    });

//    connect(this,&MainWindow::lost,[=](){
//        QLabel *r=new QLabel(this);
//        r->setText("你输了！");
//        r->setGeometry(550,300,300,100);
//        r->setStyleSheet("QLabel{border:2px solid rgb(200, 200, 200);}");
//        QPalette pal;
//        pal.setColor(QPalette::WindowText,Qt::red);
//        r->setPalette(pal);
//        QFont ft;
//        ft.setPointSize(50);
//        r->setFont(ft);
//    });

   QTimer *t = new QTimer(this);
   t->start(4000);//刷怪的时间
   connect(t,&QTimer::timeout,[=](){
      // qDebug<<QString::number(death);
       enemy *xhl=new enemy((death/5+1)*150,death/5+1-death/10);
       xhl->setParent(this);
       xhl->setStyleSheet("background-image: url(:/images/xhl.png);");
       xhl->setGeometry(220,450,35,35);
       xhl->show();
       QTimer *timer=new QTimer(this);
       timer->start(60);//帧率
       connect(pause,&QPushButton::clicked,[=](){
           timer->stop();
           t->stop();
       });
       connect(goOn,&QPushButton::clicked,[=](){
           timer->start(60);
           t->start(5000-1000*(death/10));
       });
       connect(timer,&QTimer::timeout,[=](){
           for(int i=0;i<9;i++) fire[i]=0;
           update();
           if(xhl->k==0&&xhl->y>=370) xhl->y-=xhl->speed;
           else if(xhl->k==0&&xhl->y<370) {xhl->k=1;xhl->y=370;}
           if(xhl->k==1&&xhl->x<=500) xhl->x+=xhl->speed;
           else if(xhl->k==1&&xhl->x>500) {xhl->k=2;xhl->x=500;}
           if(xhl->k==2&&xhl->y>=280) xhl->y-=xhl->speed;
           else if(xhl->k==2&&xhl->y<280) {xhl->k=3;xhl->y=280;}
           if(xhl->k==3&&xhl->x>=320) xhl->x-=xhl->speed;
           else if(xhl->k==3&&xhl->x<320) {xhl->k=4;xhl->x=320;}
           if(xhl->k==4&&xhl->y>=180) xhl->y-=xhl->speed;
           else if(xhl->k==4&&xhl->y<180) {xhl->k=5;xhl->y=180;}
           if(xhl->k==5&&xhl->x<=620) xhl->x+=xhl->speed;
           else if(xhl->k==5&&xhl->x>620) {xhl->k=6;xhl->x=620;}
           if(xhl->k==6&&xhl->y<=260) xhl->y+=xhl->speed;
           else if(xhl->k==6&&xhl->y>260) {xhl->k=7;xhl->y=260;}
           if(xhl->k==7&&xhl->x<=780) xhl->x+=xhl->speed;
           else if(xhl->k==7&&xhl->x>780) {xhl->k=8;xhl->x=780;}
           if(xhl->k==8&&xhl->y>=160) xhl->y-=xhl->speed;
           else if(xhl->k==8&&xhl->y<160)
           {
               xhl->y=160;
               xhl->setGeometry(xhl->x,xhl->y,35,35);
               hp-=1;
               if(hp==0)
               {
                   t->stop();
                   result=2;

               }
               delete xhl;              
               label->setText("hp:"+QString::number(hp)+"  "+"money："+QString::number(money)+"    ");
               timer->stop();
               update();


           }
           xhl->setGeometry(xhl->x,xhl->y,35,35);


           if(btn1->boundary(xhl)) fire[0]=1;
           if(btn2->boundary(xhl)) fire[1]=1;
           if(btn3->boundary(xhl)) fire[2]=1;
           if(btn4->boundary(xhl)) fire[3]=1;
           if(btn5->boundary(xhl)) fire[4]=1;
           if(btn6->boundary(xhl)) fire[5]=1;
           if(btn7->boundary(xhl)) fire[6]=1;
           if(btn8->boundary(xhl)) fire[7]=1;
           if(btn9->boundary(xhl)) fire[8]=1;
           update();

           if(xhl->hp<=0){
               delete xhl;
               death++;
               if(death>=150)
               {
                   t->stop();
                   result=1;
               }
               money+=100*(death/15+1);
               label->setText("hp:"+QString::number(hp)+"  "+"money："+QString::number(money));
               timer->stop();
               for(int i=0;i<9;i++) fire[i]=0;
               update();

           }

       });

   });





}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{

    QPixmap pix;
    QPainter painter(this);
    pix.load(":/images/background2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    painter.setPen(Qt::red);
    if(fire[0]==1) painter.drawLine(btn1->x,btn1->y,btn1->tx,btn1->ty);
    if(fire[1]==1) painter.drawLine(btn2->x,btn2->y,btn2->tx,btn2->ty);
    if(fire[2]==1) painter.drawLine(btn3->x,btn3->y,btn3->tx,btn3->ty);
    if(fire[3]==1) painter.drawLine(btn4->x,btn4->y,btn4->tx,btn4->ty);
    if(fire[4]==1) painter.drawLine(btn5->x,btn5->y,btn5->tx,btn5->ty);
    if(fire[5]==1) painter.drawLine(btn6->x,btn6->y,btn6->tx,btn6->ty);
    if(fire[6]==1) painter.drawLine(btn7->x,btn7->y,btn7->tx,btn7->ty);
    if(fire[7]==1) painter.drawLine(btn8->x,btn8->y,btn8->tx,btn8->ty);
    if(fire[8]==1) painter.drawLine(btn9->x,btn9->y,btn9->tx,btn9->ty);


    if(result!=0)
    {
        QRectF rect(550, 300, 360, 100);
        painter.drawRect(rect);  //为了更直观地看到字体的位置，我们绘制出这个矩形
        painter.setPen(QColor(Qt::red));
        QFont font("宋体", 50, QFont::Bold, false);   //字体，大小，粗体，斜体
        painter.setFont(font);
        if(result==1) painter.drawText(rect, Qt::AlignHCenter, "你赢了！");//字体水平居中
        else if(result==2) painter.drawText(rect,Qt::AlignHCenter,"你输了！");
    }


}
void MainWindow::change(spotbutton *p)
{
    if(p->k==0)
    {
        if(flag==1&&money>=100) {
            money-=100;
            p->setIcon(QIcon(":/images/tower.png"));
            p->attack=1;
            p->k=1;
        }
        else if(flag==2&&money>=200) {
            money-=200;
            p->setIcon(QIcon(":/images/tower1.png"));
            p->attack=2;
            p->k=2;
        }
        else if(flag==3&&money>=300){
            money-=300;
            p->setIcon(QIcon(":/images/tower2.png"));
            p->attack=3;
            p->k=3;

        }
        else if(flag==4&&money>=400){
            money-=400;
            p->setIcon(QIcon(":/images/tower3.png"));
            p->attack=4;
            p->k=4;
        }
        label->setText("hp:"+QString::number(hp)+"  "+"money："+QString::number(money));
    }
    else if(flag==5){
        p->setIcon(QIcon(":/images/open_spot.png"));
        p->attack=0;
        switch (p->k) {
        case 1:money+=50;break;
        case 2:money+=100;break;
        case 3:money+=150;break;
        case 4:money+=200;break;

        }
        label->setText("hp:"+QString::number(hp)+"  "+"money："+QString::number(money));
        p->k=0;

    }
    else if(flag==6&&money>=400*(death/20+1))
    {
        p->attack+=5+death/10;
        money-=400*(death/20+1);
        label->setText("hp:"+QString::number(hp)+"  "+"money："+QString::number(money));
        QPixmap pix;
        switch (p->k) {
        case 1: pix.load(":/images/newtower.png");break;
        case 2: pix.load(":/images/newtower1.png");break;
        case 3: pix.load(":/images/newtower2.png");break;
        case 4: pix.load(":/images/newtower3.png");break;
        }
        p->setFixedSize(pix.width(),pix.height());
        p->setIcon(pix);
        p->setIconSize(QSize(pix.width(),pix.height()));
        p->setStyleSheet("QPushButton{border:0px;}");
        p->move(p->x-35,p->y-35);
    }
}
