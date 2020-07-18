#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QPaintEvent>
#include<QPixmap>
#include<QPainter>
#include<QLabel>
#include<QMainWindow>
class enemy : public QLabel
{
    Q_OBJECT
public:
    enemy();
    enemy(int hhpp,int vv);
    int hp;
    int speed;
    QPixmap imge;
    QPoint pos_e;
    int k=0,x,y;
signals:


};

#endif // ENEMY_H
