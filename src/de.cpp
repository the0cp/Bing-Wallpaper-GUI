#include "include/de.h"
#include "ui_de.h"

DE::DE(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DE)
{
    ui->setupUi(this);
}

DE::~DE()
{
    delete ui;
}
