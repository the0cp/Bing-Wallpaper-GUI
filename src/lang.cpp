#include "include/lang.h"
#include "ui_lang.h"
#include "include/proc.h"

LANG::LANG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LANG)
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    ui->setupUi(this);
    groupButton=new QButtonGroup(this);
    groupButton -> addButton(ui -> rbtn_enus, 0);
    groupButton -> addButton(ui -> rbtn_frfr, 1);
    groupButton -> addButton(ui -> rbtn_frca, 2);
    groupButton -> addButton(ui -> rbtn_gege, 3);
    groupButton -> addButton(ui -> rbtn_ruru, 4);
    groupButton -> addButton(ui -> rbtn_zhcn, 5);
    groupButton -> addButton(ui -> rbtn_zhtw, 6);

    groupButton->button(settings.value("Language/default").toInt())->setChecked(1);
}

LANG::~LANG()
{
    delete ui;
}

void LANG::checkLang()
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
            settings.setValue("Language/default", 0);
            break;
        case 1:
            settings.setValue("Language/default", 1);
            break;
        case 2:
            settings.setValue("Language/default", 2);
            break;
        case 3:
            settings.setValue("Language/default", 3);
            break;
        case 4:
            settings.setValue("Language/default", 4);
            break;
        case 5:
            settings.setValue("Language/default", 5);
            break;
        case 6:
            settings.setValue("Language/default", 6);
            break;
    }
}

void LANG::on_buttonBox_clicked(QAbstractButton *button)
{

    if(ui->buttonBox->button(QDialogButtonBox::Ok)  == button)
    {
        checkLang();
    }
    else
    {
        reject();
    }
}
