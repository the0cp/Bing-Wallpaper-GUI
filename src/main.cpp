#include "include/bingbg.h"
#include "ui_bingbg.h"
#include "include/proc.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    /*
    char *time = geTime();
    char *user = getlogin();
    qDebug()<<time<<endl;
    qDebug()<<user<<endl;
    makeDir(time, user);
    */
    QApplication a(argc, argv);
    BingBG w;
    w.show();
    return a.exec();
}
