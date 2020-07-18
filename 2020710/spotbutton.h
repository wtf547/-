#ifndef SPOTBUTTON_H
#define SPOTBUTTON_H

#include <QPushButton>
#include<QMainWindow>
#include<enemy.h>
class spotbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit spotbutton(QMainWindow *parent = nullptr);
    spotbutton(QString t);
    void smove(int a,int b);
    bool boundary(enemy *p);
    int fee=0;
    int attack=0;
    int k=0;
    int x,y;
    int tx,ty;

signals:


};

#endif // SPOTBUTTON_H
