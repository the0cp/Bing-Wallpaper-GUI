#include "include/proxy.h"
#include "ui_proxy.h"
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
}

void Proxy::setProxy()
{
    switch(groupButton -> checkedId())
    {
        case 0:
            break;
        case 1:
            QNetworkAccessManager *manager;
            QNetworkProxyQuery proxyQuery(QUrl("https://www.github.com"));
            QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
            if(proxyList.count() > 0)
            {
                manager.setProxy(proxyList.at(0));
            }
            qDebug()<<"ddd"<<endl;
            break;
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
        qDebug()<<"ddd"<<endl;
    }
    else
    {
        reject();
    }
}
