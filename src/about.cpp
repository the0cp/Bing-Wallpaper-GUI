#include "include/about.h"
#include "ui_about.h"
#include "include/proc.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}


void About::on_btnClose_clicked()
{
    qDebug()<<"Exit About"<<endl;
    exit(1);
}
