#include "include/exitconfirmation.h"
#include "ui_exitconfirmation.h"

exitConfirmation::exitConfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exitConfirmation)
{
    ui->setupUi(this);
}

exitConfirmation::~exitConfirmation()
{
    delete ui;
}


void exitConfirmation::on_btnExit_clicked()
{
    exit(1);
}
