#include "include/de.h"
#include "include/proc.h"
#include "ui_de.h"

DE::DE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DE)
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    ui->setupUi(this);
    groupButton=new QButtonGroup(this);
    groupButton -> addButton(ui -> rbtn_mate, 0);
    groupButton -> addButton(ui -> rbtn_xfce, 1);
    groupButton -> addButton(ui -> rbtn_gnome, 2);
    groupButton -> addButton(ui -> rbtn_cinn, 3);

    //groupButton->button(settings.value("DesktopEnvironment/default").toInt())->setChecked(1);
}

DE::~DE()
{
    delete ui;
}

void DE::checkDE()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    switch(groupButton->checkedId())
    {
        case 0:
            settings.setValue("DesktopEnvironment/default", 0);
            break;
        case 1:
            settings.setValue("DesktopEnvironment/default", 1);
            break;
        case 2:
            settings.setValue("DesktopEnvironment/default", 2);
            break;
        case 3:
            settings.setValue("DesktopEnvironment/default", 3);
            break;
        default:
            break;
    }
}

void DE::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok)  == button)
    {
        qDebug()<<"set de"<<endl;
        checkDE();
    }
    else
    {
        qDebug()<<"reject de"<<endl;
        reject();
    }
}
