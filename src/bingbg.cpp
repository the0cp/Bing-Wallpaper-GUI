#include "include/bingbg.h"
#include "ui_bingbg.h"
#include "include/proc.h"

BingBG::BingBG(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BingBG)
{
    ui->setupUi(this);
    ui -> progressBar -> setMinimum(0);
    ui -> progressBar -> setMaximum(100);
    ui -> progressBar->setValue(0);

    connect(ui -> actionAbout, SIGNAL(triggered()), this, SLOT(openAbout()));
    connect(ui -> actionAuthor, SIGNAL(triggered()), this, SLOT(openAuthor()));
    initDownload();
}

BingBG::~BingBG()
{
    delete ui;
}

void BingBG::on_btnExit_clicked()
{
    qDebug()<<"clicked Exit"<<endl;
    p_confirm = new exitConfirmation;
    p_confirm -> show();
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

void BingBG::openAuthor()
{
    qDebug()<<"open Author"<<endl;
    p_OpenAuthor = new Author;
    p_OpenAuthor -> show();
}

void BingBG::initDownload()
{
    manager = new QNetworkAccessManager(this);
    files = new QFile(this);
}

void BingBG::doProcessReadyRead()
{
    while(!reply->atEnd())
    {
        QByteArray ba = reply->readAll();
        files->write(ba);
    }
}

void BingBG::doProcessFinished()
{
    files->close();
}

void BingBG::doProcessDownloadProgress(qint64 recv_total, qint64 all_total)
{
    ui->progressBar->setMaximum(all_total);
    ui->progressBar->setValue(recv_total);
}

void BingBG::doProcessError(QNetworkReply::NetworkError code)
{
    qDebug() << code;
}

void BingBG::download(QString URL, QString PATH)
{
    QNetworkRequest request;
    QString url = URL;
    request.setUrl(QUrl(url));
    reply = manager -> get(request);
    connect(reply, &QNetworkReply::readyRead, this, &BingBG::doProcessReadyRead);
    connect(reply, &QNetworkReply::finished, this, &BingBG::doProcessFinished);
    connect(reply, &QNetworkReply::downloadProgress, this, &BingBG::doProcessDownloadProgress);
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this, &BingBG::doProcessError);
    QStringList list = url.split("/");
    files->setFileName(PATH);
    bool ret = files->open(QIODevice::WriteOnly|QIODevice::Truncate);
    if(!ret)
    {
        return;
    }
    ui->progressBar->setValue(0);
    ui->progressBar->setMinimum(0);
}


void BingBG::on_btnFetch_clicked()
{
    qDebug()<<"Start"<<endl;
    ui -> btnFetch -> setDisabled(true);
    char *time = geTime();
    char *user = getlogin();
    qDebug()<<time<<endl;
    qDebug()<<user<<endl;
    makeDir(time, user);
    char *hhh = "https://www.bing.com/th?id=OHR.Kinkakuji_EN-US8643828412_1920x1080.jpg&rf=LaDigue_1920x1080.jpg&pid=hp";
    QString str(hhh);
    QString sttr = "/home/theodore/wallpaper.jpg";
    download(str, sttr);


    //ui -> btnFetch -> setDisabled(false);
}
