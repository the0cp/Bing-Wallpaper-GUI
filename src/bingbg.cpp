#include "include/bingbg.h"
#include "ui_bingbg.h"
#include "include/proc.h"

BingBG::BingBG(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BingBG)
{
    ui->setupUi(this);
    readState();
    char *imgPath;
    char *time = geTime();
    char *user = getlogin();
    asprintf(&imgPath, "%s%s%s%s%s", "/home/", user, "/BBG-Download/", time, "/Wallpaper.jpg");
    qDebug()<<imgPath<<endl;
    if(access(imgPath, 0) == 0)
    {
        showImg();
    }
    ui -> progressBar -> setMinimum(0);
    ui -> progressBar -> setMaximum(100);
    ui -> progressBar->setValue(0);

    connect(ui -> actionAbout, SIGNAL(triggered()), this, SLOT(openAbout()));
    connect(ui -> actionAuthor, SIGNAL(triggered()), this, SLOT(openAuthor()));
    connect(ui -> actionDesktop_Environment, SIGNAL(triggered()), this, SLOT(openDE()));
    initDownload();
}

BingBG::~BingBG()
{
    delete ui;
}

void BingBG::writeState()
{
    QSettings settings("Theodore Cooper", "Bingbg");

    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.setValue("JDCheck", ui->checkJd->isChecked());
    settings.endGroup();
}

void BingBG::readState()
{
    QSettings settings("Theodore Cooper", "Bingbg");

    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200,200)).toPoint());
    ui->checkJd->setChecked(settings.value("JDCheck").toBool());
    settings.endGroup();
}

void BingBG::on_btnExit_clicked()
{
    qDebug()<<"clicked Exit"<<endl;
    if (!(QMessageBox::warning(this,tr("exit tip"),tr("Do you really want to quit Bing Backgrounds Getter?"),tr("Yes"),tr("No"))))
    {
        writeState();
        exit(0);
    }
}


void BingBG::closeEvent(QCloseEvent *event)
{
    if (!(QMessageBox::warning(this,tr("exit tip"),tr("Do you really want to quit Bing Backgrounds Getter?"),tr("Yes"),tr("No"))))
    {
        writeState();
        event -> accept();
    }
    else
    {
        event -> ignore();
    }
}

void BingBG::on_btnOpenfolder_clicked()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString folderPath = "file:/home/" + quser + "/BBG-Download/" + qtime;
    //QString imgPath = folderPath + "/Wallpaper.jpg";
    qDebug()<<"open file in file explorer"<<endl;
    QDesktopServices::openUrl(QUrl(folderPath, QUrl::TolerantMode));
}

void BingBG::on_btnOpenimg_clicked()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString folderPath = "file:/home/" + quser + "/BBG-Download/" + qtime + "/Wallpaper.jpg";
    qDebug()<<"open file in image viewer"<<endl;
    QDesktopServices::openUrl(QUrl(folderPath, QUrl::TolerantMode));
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

void BingBG::openDE()
{
    qDebug()<<"open Settings"<<endl;
    p_OpenDE = new DE;
    p_OpenDE -> show();
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
    ui->labelCurrent->setText("Done!!!");
    files -> flush();
    files -> close();
}

void BingBG::enableBtn()
{
    ui -> btnFetch -> setDisabled(false);
}

void BingBG::showImg()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString imgPath = "/home/" + quser + "/BBG-Download/" + qtime + "/Wallpaper.jpg";
    QImage *img = new QImage;
    img->load(imgPath);

    ui->labelImg->setPixmap(QPixmap::fromImage(*img));}

void BingBG::doProcessDownloadProgress(qint64 recv_total, qint64 all_total)
{
    ui->progressBar->setMaximum(all_total);
    ui->progressBar->setValue(recv_total);
}

void BingBG::doProcessError(QNetworkReply::NetworkError code)
{
    qDebug() << code;
}

void BingBG::core_downloadXml(QString URL, QString PATH)
{
    ui->labelCurrent->setText("downloading xml...");
    QNetworkRequest request;
    QString url = URL;
    request.setUrl(QUrl(url));
    reply = manager -> get(request);
    connect(reply, &QNetworkReply::readyRead, this, &BingBG::doProcessReadyRead);
    connect(reply, &QNetworkReply::finished, this, &BingBG::doProcessFinished);
    connect(reply, &QNetworkReply::downloadProgress, this, &BingBG::doProcessDownloadProgress);
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this, &BingBG::doProcessError);
    connect(reply, &QNetworkReply::finished, this, &BingBG::downloadImg);


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

void BingBG::core_downloadImg(QString URL, QString PATH)
{
    ui->labelCurrent->setText("downloading img...");
    QNetworkRequest request;
    QString url = URL;
    request.setUrl(QUrl(url));
    reply = manager -> get(request);
    connect(reply, &QNetworkReply::readyRead, this, &BingBG::doProcessReadyRead);
    connect(reply, &QNetworkReply::finished, this, &BingBG::doProcessFinished);
    connect(reply, &QNetworkReply::finished, this, &BingBG::showImg);
    connect(reply, &QNetworkReply::finished, this, &BingBG::enableBtn);
    if(ui->checkJd->isChecked() == 0)
    {
        connect(reply, &QNetworkReply::finished, this, &BingBG::setBG);
    }

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

void BingBG::downloadXml()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString folderPath = "/home/" + quser + "/BBG-Download/" + qtime;
    QString xmlUrl = "https://www.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1&mkt=en-US";
    QString xmlPath = folderPath + "/index.xml";
    core_downloadXml(xmlUrl, xmlPath);
}

void BingBG::downloadImg()
{
    char *time = geTime();
    char *user = getlogin();
    char *imgUrl_full = parseXml(time, user);
    if(imgUrl_full == NULL)
    {
        qDebug()<<"<Failed to parse xml>"<<endl;
    }
    else
    {
        qDebug()<<imgUrl_full<<endl;
        QString qtime(time);
        QString quser(user);
        QString qimgUrl_full(imgUrl_full);
        QString folderPath = "/home/" + quser + "/BBG-Download/" + qtime;
        QString imgPath = folderPath + "/Wallpaper.jpg";
        core_downloadImg(qimgUrl_full, imgPath);
    }
}

void BingBG::setBG()
{
    qDebug()<<"set backgrounds!!!"<<endl;
}

void BingBG::on_btnFetch_clicked()
{
    ui->labelCurrent->setText("init...");
    qDebug()<<"Start"<<endl;
    ui -> btnFetch -> setDisabled(true);
    char *time = geTime();
    char *user = getlogin();
    qDebug()<<time<<endl;
    qDebug()<<user<<endl;
    ui->labelCurrent->setText("making folders...");
    makeDir(time, user);
    QString qtime(time);
    QString quser(user);
    QString confPath = "/home/" + quser + "/.bingbg/" + "qt-config.xml";
    ui->labelImg->setText("...");
    downloadXml();

    //ui -> btnFetch -> setDisabled(false);
}

