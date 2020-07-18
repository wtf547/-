#ifndef BEGINBACKGROUND_H
#define BEGINBACKGROUND_H

#include <QMainWindow>
#include"mainwindow.h"
#include<QPushButton>

class beginbackground : public QMainWindow
{
    Q_OBJECT
public:
    explicit beginbackground(QWidget *parent = nullptr);
    ~beginbackground();
    MainWindow * main = NULL;
    QPushButton startbtn;
signals:

};

#endif // BEGINBACKGROUND_H
