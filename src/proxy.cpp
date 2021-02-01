#include "include/proxy.h"
#include "ui_proxy.h"
#include "include/proc.h"
#include <QDebug>
#include <QAbstractSocket>
#include <QNetworkAccessManager>

Proxy::Proxy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Proxy)
{
    ui->setupUi(this);
    groupButton=new QButtonGroup(this);
    groupButton -> addButton(ui -> rbtn_noproxy, 0);
    groupButton -> addButton(ui -> rbtn_sys, 1);
    groupButton -> addButton(ui -> rbtn_manual, 2);
    readState();

    char *user = getlogin();
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    if(settings.value("Network/Proxy").toInt() == 2)
    {
        ui -> frame -> setEnabled(true);
    }
    else
    {
        ui -> frame -> setEnabled(false);
    }
}

void Proxy::writeState()
{
    QSettings state("Theodore Cooper", "Bingbg");

    state.beginGroup("Proxy");
    state.setValue("size", size());
    state.setValue("pos", pos());
    state.endGroup();
}

void Proxy::readState()
{
    QSettings state("Theodore Cooper", "Bingbg");
    char *user = getlogin();
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);

    state.beginGroup("Proxy");
    resize(state.value("size", QSize(400, 400)).toSize());
    move(state.value("pos", QPoint(200,200)).toPoint());
    groupButton -> button(settings.value("Network/Proxy").toInt())->setChecked(true);
    ui->proxyType->setCurrentIndex(settings.value("Proxy/Type").toInt());
    state.endGroup();
}

void Proxy::setProxy()
{
    char *user = getlogin();
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    switch(groupButton -> checkedId())
    {
        case 0:
            settings.setValue("Network/Proxy", 0);
            break;
        case 1:
            settings.setValue("Network/Proxy", 1);
            break;
        case 2:
            settings.setValue("Network/Proxy", 2);
            settings.setValue("Proxy/Type", ui -> proxyType -> currentIndex());
            settings.setValue("Proxy/Hostname", ui -> hostname -> text());
            settings.setValue("Proxy/Port", ui -> port -> text());
            settings.setValue("Proxy/Username", ui -> usrname -> text());
            settings.setValue("Proxy/Password", ui -> password -> text());
    }
}

Proxy::~Proxy()
{
    delete ui;
}

void Proxy::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        setProxy();
        writeState();
    }
    else
    {
        reject();
    }
}

void Proxy::on_rbtn_manual_clicked(bool checked)
{
    ui -> frame -> setEnabled(true);
}

void Proxy::on_rbtn_sys_clicked(bool checked)
{
    ui -> frame -> setEnabled(false);
}

void Proxy::on_rbtn_noproxy_clicked(bool checked)
{
    ui -> frame -> setEnabled(false);
}
