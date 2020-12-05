#include "include/bingbg.h"
#include "ui_bingbg.h"
#include "include/proc.h"
#include "include/download.h"

BingBG::BingBG(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BingBG)
{
    ui->setupUi(this);

    connect(ui -> actionAbout, SIGNAL(triggered()), this, SLOT(openAbout()));
}

BingBG::~BingBG()
{
    delete ui;
}


void BingBG::on_btnExit_clicked()
{
    qDebug()<<"clicked Exit"<<endl;
    exit(1);
}

void BingBG::on_btnOpenimg_clicked()
{
    qDebug()<<"open file in file explorer"<<endl;
}

void BingBG::openAbout()
{
    qDebug()<<"open About"<<endl;
    p_OpenAbout = new About;
    p_OpenAbout -> show();
}

void BingBG::on_btnFetch_clicked()
{
    qDebug()<<"Start"<<endl;
    /*
     * Set button disabled
     *
     */
    char *time = geTime();
    char *user = getlogin();
    qDebug()<<time<<endl;
    qDebug()<<user<<endl;
    makeDir(time, user);
    downloadXml(time, user);
    downloadImg(time, user);
    /*
     * Set button unabled
     *
     */
}
