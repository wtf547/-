#include "spotbutton.h"

spotbutton::spotbutton(QMainWindow *parent) : QPushButton(parent)
{

}
spotbutton::spotbutton(QString t)
{
    QPixmap pix;
    pix.load(t);
    this->setFixedSize(pix.width(),pix.height());
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
    this->setStyleSheet("QPushButton{border:0px;}");
}
void spotbutton::smove(int a, int b)
{
    x=a+17;
    y=b+17;
}
bool spotbutton::boundary(enemy *p)
{
    if(k==0) return false;
    tx=p->x+17;
    ty=p->y+17;
    int a=x-p->x;
    int b=y-p->y;
    int dis=a*a+b*b;
    if(dis<10000)
    {
        p->hp-=attack;
        return true;
    }
    else return false;
}
