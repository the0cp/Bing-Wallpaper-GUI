#include "include/bingbg.h"
#include "ui_bingbg.h"
#include "include/proc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    char *time = geTime();
    char *user = getlogin();
    char *confPath;
    asprintf(&confPath, "%s%s%s", "/home/", user, "/.bingbg/qt-config.ini");
    if(access(confPath, 0) == -1)
    {
        QString qtime(time);
        QString quser(user);
        QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
        QSettings settings(qconfPath, QSettings::IniFormat);
        settings.setValue("DesktopEnvironment/default", -1);
    }
    BingBG w;
    w.show();
    return a.exec();
}
