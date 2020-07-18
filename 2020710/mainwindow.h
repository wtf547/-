#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QPainter>

#include"enemy.h"

#include"spotbutton.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void change(spotbutton *p);
    void paintEvent(QPaintEvent *);
    int flag=0;
    int fire[9]={0};
    int hp=10,money=400;
    int result=0;
    spotbutton * btn1 = new  spotbutton(":/images/open_spot.png");
    spotbutton * btn2 = new  spotbutton(":/images/open_spot.png");
    spotbutton * btn3 = new  spotbutton(":/images/open_spot.png");
    spotbutton * btn4 = new  spotbutton(":/images/open_spot.png");
    spotbutton * btn5 = new  spotbutton(":/images/open_spot.png");
    spotbutton * btn6 = new  spotbutton(":/images/open_spot.png");
    spotbutton * btn7 = new  spotbutton(":/images/open_spot.png");
    spotbutton * btn8 = new  spotbutton(":/images/open_spot.png");
    spotbutton * btn9 = new  spotbutton(":/images/open_spot.png");
    QLabel *label=new QLabel(this);
    Ui::MainWindow *ui;

signals:
    void lost();
};
#endif // MAINWINDOW_H
