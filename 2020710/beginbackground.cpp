#include "beginbackground.h"
#include<QTimer>
beginbackground::beginbackground(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,500);
    this->setStyleSheet("background-image: url(:/images/bcg.png);");
    this->setWindowIcon(QIcon(":/images/icon_gold.png"));
    this->setWindowTitle("开始界面");
    startbtn.setParent(this);
    startbtn.move(400,200);
    startbtn.setText("开始游戏");
    startbtn.resize(200,100);
    main = new MainWindow;

    connect(&startbtn,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(500,this,[=](){
            this->hide();
            main->show();
        });

    });
}
beginbackground::~beginbackground()
{
//    delete main->ui;
}
