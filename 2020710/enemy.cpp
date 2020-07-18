#include "enemy.h"
#include<QPixmap>
#include<QPainter>
#include<QMainWindow>
#include"mainwindow.h"
#include<QLabel>
enemy::enemy() : hp(200),speed(5)
{
    setStyleSheet("background-image: url(:/images/xhl.png);");
//    pos_e=QPoint(1400,700);
    x=220;
    y=450;

}
enemy::enemy(int hhpp,int vv)
{
    x=220;
    y=450;
    hp=hhpp;
    speed=vv;

}

