#include "include/bingbg.h"
#include "include/proc.h"
#include "include/setbg.h"
#include "ui_bingbg.h"

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
    if(access(imgPath, 0) == 0)
    {
        showImg();
    }
    ui -> progressBar -> setMinimum(0);
    ui -> progressBar -> setMaximum(100);
    ui -> progressBar -> setValue(0);

    connect(ui -> actionAbout, SIGNAL(triggered()), this, SLOT(openAbout()));
    connect(ui -> actionAuthor, SIGNAL(triggered()), this, SLOT(openAuthor()));
    connect(ui -> actionDesktop_Environment, SIGNAL(triggered()), this, SLOT(openDE()));
    connect(ui -> actionLanguage, SIGNAL(triggered()), this, SLOT(openLANG()));
    connect(ui -> actionProxy, SIGNAL(triggered()), this, SLOT(openProxy()));
    initDownload();

    //init system tray
    systray.setToolTip("Bing Backgrounds Getter");
    systray.setIcon(QIcon(":/Bingbg-icon.png"));

    //init tray menu
    traymenu = new QMenu;
    traymenu -> addAction(ui -> actionFetch);
    traymenu -> addAction(ui -> actionShow);
    traymenu -> addAction(ui -> actionExitTray);
    systray.setContextMenu(traymenu);

    connect(&systray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(OnSystemTrayClicked(QSystemTrayIcon::ActivationReason)));
    systray.show();

    connect(ui -> actionExitTray, SIGNAL(triggered()), this, SLOT(on_btnExit_clicked()));
    connect(ui -> actionShow, SIGNAL(triggered()), this, SLOT(showMainwindow()));
    connect(ui -> actionFetch, SIGNAL(triggered()), this, SLOT(on_btnFetch_clicked()));
}

BingBG::~BingBG()
{
    delete ui;
}

void BingBG::writeState()
{
    QSettings state("Theodore Cooper", "Bingbg");

    state.beginGroup("MainWindow");
    state.setValue("size", size());
    state.setValue("pos", pos());
    state.setValue("JDCheck", ui -> checkJd -> isChecked());
    state.endGroup();
}

void BingBG::readState()
{
    QSettings state("Theodore Cooper", "Bingbg");

    state.beginGroup("MainWindow");
    resize(state.value("size", QSize(400, 400)).toSize());
    move(state.value("pos", QPoint(200,200)).toPoint());
    ui -> checkJd -> setChecked(state.value("JDCheck").toBool());
    state.endGroup();

    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    loadLanguage(settings.value("Language/default").toInt());
}

void BingBG::on_btnExit_clicked()
{
    if (!(QMessageBox::warning(this,tr("Exit?"),tr("Do you really want to quit Bing Backgrounds Getter?"),tr("Yes"),tr("No"))))
    {
        writeState();
        exit(0);
    }
}


void BingBG::closeEvent(QCloseEvent *event)
{
    /*
    if (!(QMessageBox::warning(this,tr("Exit?"),tr("Do you really want to quit Bing Backgrounds Getter?"),tr("Yes"),tr("No"))))
    {
        writeState();
        event -> accept();
    }
    else
    {
        event -> ignore();
    }*/
    writeState();
    this -> hide();
    event -> ignore();
}

void BingBG::on_btnOpenfolder_clicked()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString folderPath = "file:/home/" + quser + "/BBG-Download/" + qtime;
    //QString imgPath = folderPath + "/Wallpaper.jpg";
    QDesktopServices::openUrl(QUrl(folderPath, QUrl::TolerantMode));
}

void BingBG::on_btnOpenimg_clicked()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString folderPath = "file:/home/" + quser + "/BBG-Download/" + qtime + "/Wallpaper.jpg";
    QDesktopServices::openUrl(QUrl(folderPath, QUrl::TolerantMode));
}

int BingBG::OnSystemTrayClicked(QSystemTrayIcon::ActivationReason REASON)
{
    if(REASON == QSystemTrayIcon::Trigger || REASON == QSystemTrayIcon::DoubleClick)
    {
        //show main window
        this -> showNormal();
    }
    return 0;
}

void BingBG::openAbout()
{
    p_OpenAbout = new About;
    p_OpenAbout -> show();
}

void BingBG::openAuthor()
{
    p_OpenAuthor = new Author;
    p_OpenAuthor -> show();
}

void BingBG::openDE()
{
    p_OpenDE = new DE;
    p_OpenDE -> show();
}

void BingBG::openLANG()
{
    p_OpenLANG = new LANG;
    p_OpenLANG -> show();
}

void BingBG::openProxy()
{
    p_OpenProxy = new Proxy;
    p_OpenProxy -> show();
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
    ui->statusbar->showMessage(tr("Done!!!"),0);
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
    if(img->load(imgPath) == 1)
    {
        ui->labelImg->setPixmap(QPixmap::fromImage(*img));
    }
}

void BingBG::showMainwindow()
{
    this -> showNormal();
}

void BingBG::doProcessDownloadProgress(qint64 recv_total, qint64 all_total)
{
    ui -> progressBar -> setMaximum(all_total);
    ui -> progressBar -> setValue(recv_total);
}

void BingBG::doProcessError(QNetworkReply::NetworkError code)
{
    QString error_code(code);
    ui -> labelCurrent -> setText(error_code);
    ui->statusbar->showMessage(error_code,0);
}

void BingBG::core_downloadXml(QString URL, QString PATH)
{
    char *user = getlogin();
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);

    ui -> labelCurrent -> setText("downloading xml...");
    ui->statusbar->showMessage(tr("downloading xml..."),0);

    QNetworkProxy proxy;
    switch(settings.value("Network/Proxy").toInt())
    {
        case 0:
        {
            manager -> setProxy(QNetworkProxy::NoProxy);
            break;
        }
        case 1:
        {
            QNetworkProxyQuery proxyQuery(QUrl("www.github.com"));
            proxyQuery.setQueryType(QNetworkProxyQuery::UrlRequest);
            proxyQuery.setProtocolTag("http");
            QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
            if(proxyList.size() > 0 && proxyList[0].type() != QNetworkProxy::NoProxy)
            {
                QNetworkProxy::setApplicationProxy(proxyList[0]);
            }
            //QNetworkProxyFactory::setUseSystemConfiguration(true);
            break;
        }
        case 2:
        {
            switch (settings.value("Proxy/Type").toInt())
            {
                case 0:
                {
                    proxy.setType(QNetworkProxy::HttpProxy);
                    proxy.setHostName(settings.value("Proxy/Hostname").toString());
                    proxy.setPort(settings.value("Proxy/Port").toInt());
                    proxy.setUser(settings.value("Proxy/Username").toString());
                    proxy.setPassword(settings.value("Proxy/Password").toString());
                    manager -> setProxy(proxy);
                    break;
                }
                case 1:
                {
                    proxy.setType(QNetworkProxy::Socks5Proxy);
                    proxy.setHostName(settings.value("Proxy/Hostname").toString());
                    proxy.setPort(settings.value("Proxy/Port").toInt());
                    proxy.setUser(settings.value("Proxy/Username").toString());
                    proxy.setPassword(settings.value("Proxy/Password").toString());
                    manager -> setProxy(proxy);
                    break;
                }
                case 2:
                {
                    proxy.setType(QNetworkProxy::Socks5Proxy);
                    proxy.setHostName(settings.value("Proxy/Hostname").toString());
                    proxy.setPort(settings.value("Proxy/Port").toInt());
                    proxy.setUser(settings.value("Proxy/Username").toString());
                    proxy.setPassword(settings.value("Proxy/Password").toString());
                    manager -> setProxy(proxy);
                    break;
                }
            }
            break;
        }
    }

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
    files -> setFileName(PATH);
    bool ret = files -> open(QIODevice::WriteOnly|QIODevice::Truncate);
    if(!ret)
    {
        return;
    }
    ui -> progressBar -> setValue(0);
    ui -> progressBar -> setMinimum(0);
}

void BingBG::core_downloadImg(QString URL, QString PATH)
{
    char *user = getlogin();
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);

    ui -> labelCurrent -> setText("downloading img...");
    ui->statusbar->showMessage(tr("downloading img..."),0);

    QNetworkProxy proxy;
    switch(settings.value("Network/Proxy").toInt())
    {
        case 0:
        {
            manager -> setProxy(QNetworkProxy::NoProxy);
            break;
        }
        case 1:
        {
            QNetworkProxyQuery proxyQuery(QUrl("www.github.com"));
            proxyQuery.setQueryType(QNetworkProxyQuery::UrlRequest);
            proxyQuery.setProtocolTag("http");
            QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
            if(proxyList.size() > 0 && proxyList[0].type() != QNetworkProxy::NoProxy)
            {
                QNetworkProxy::setApplicationProxy(proxyList[0]);
            }
            //QNetworkProxyFactory::setUseSystemConfiguration(true);
            break;
        }
        case 2:
        {
            switch (settings.value("Proxy/Type").toInt())
            {
                case 0:
                {
                    proxy.setType(QNetworkProxy::HttpProxy);
                    proxy.setHostName(settings.value("Proxy/Hostname").toString());
                    proxy.setPort(settings.value("Proxy/Port").toInt());
                    proxy.setUser(settings.value("Proxy/Username").toString());
                    proxy.setPassword(settings.value("Proxy/Password").toString());
                    manager -> setProxy(proxy);
                    break;
                }
                case 1:
                {
                    proxy.setType(QNetworkProxy::Socks5Proxy);
                    proxy.setHostName(settings.value("Proxy/Hostname").toString());
                    proxy.setPort(settings.value("Proxy/Port").toInt());
                    proxy.setUser(settings.value("Proxy/Username").toString());
                    proxy.setPassword(settings.value("Proxy/Password").toString());
                    manager -> setProxy(proxy);
                    break;
                }
                case 2:
                {
                    proxy.setType(QNetworkProxy::Socks5Proxy);
                    proxy.setHostName(settings.value("Proxy/Hostname").toString());
                    proxy.setPort(settings.value("Proxy/Port").toInt());
                    proxy.setUser(settings.value("Proxy/Username").toString());
                    proxy.setPassword(settings.value("Proxy/Password").toString());
                    manager -> setProxy(proxy);
                    break;
                }
            }
            break;
        }
    }

    QNetworkRequest request;
    QString url = URL;
    request.setUrl(QUrl(url));
    reply = manager -> get(request);
    connect(reply, &QNetworkReply::readyRead, this, &BingBG::doProcessReadyRead);
    connect(reply, &QNetworkReply::finished, this, &BingBG::doProcessFinished);
    connect(reply, &QNetworkReply::finished, this, &BingBG::showImg);
    connect(reply, &QNetworkReply::finished, this, &BingBG::enableBtn);
    if(ui -> checkJd -> isChecked() == 1)
    {
        connect(reply, &QNetworkReply::finished, this, &BingBG::setBG);
    }

    connect(reply, &QNetworkReply::downloadProgress, this, &BingBG::doProcessDownloadProgress);
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this, &BingBG::doProcessError);
    QStringList list = url.split("/");
    files->setFileName(PATH);
    bool ret = files -> open(QIODevice::WriteOnly|QIODevice::Truncate);
    if(!ret)
    {
        return;
    }
    ui -> progressBar -> setValue(0);
    ui -> progressBar -> setMinimum(0);
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
    QString qimgUrl_full = parseXml(time, user);
    if(qimgUrl_full == NULL)
    {
        ui -> labelCurrent -> setText("Failed to parse Xml!!!");
        ui->statusbar->showMessage(tr("Failed to parse Xml!!!"),0);
    }
    else
    {
        QString qtime(time);
        QString quser(user);
        QString folderPath = "/home/" + quser + "/BBG-Download/" + qtime;
        QString imgPath = folderPath + "/Wallpaper.jpg";
        core_downloadImg(qimgUrl_full, imgPath);
    }
}

void BingBG::setBG()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    switch (settings.value("DesktopEnvironment/default").toInt())
    {
        case -1:
            BingBG::openDE();
            break;
        case 0:
            setBG::setBG_MATE(time, user);
            break;
        case 1:
            setBG::setBG_XFCE(time, user);
            break;
        case 2:
            setBG::setBG_GNOME(time, user);
            break;
        case 3:
            setBG::setBG_CINNAMON(time, user);
            break;
    }
}

void BingBG::on_btnSetbg_clicked()
{
    setBG();
}

void BingBG::autoStart()
{
    on_btnFetch_clicked();
}

void BingBG::setAutoStart()
{
    const char *cmd = "cp /usr/share/applications/BingBG.desktop.desktop $HOME/.config/autostart/BingBG.desktop";
    system(cmd);
}

void BingBG::rmAutoStart()
{
    const char *cmd = "rm -f $HOME/.config/autostart/BingBG.desktop";
    system(cmd);
}

void BingBG::checkAutoStart()
{
    char *user = getlogin();
    char *autoStart;
    asprintf(&autoStart, "%s%s%s", "/home/", user, "/.config/autostart/BingBG.desktop");
    if(access(autoStart, 0) == -1)
    {
        ui -> actionAutoStart -> setChecked(true);
        //set action true
    }
    else
    {
        ui -> actionAutoStart -> setChecked(false);
        //set false
    }
}

void BingBG::on_btnFetch_clicked()
{
    ui -> labelCurrent -> setText("init...");
    ui->statusbar->showMessage(tr("init..."),0);
    ui -> btnFetch -> setDisabled(true);
    char *time = geTime();
    char *user = getlogin();
    ui -> labelCurrent -> setText("making folders...");
    ui->statusbar->showMessage(tr("making folders..."),0);
    makeDir(time, user);
    QString qtime(time);
    QString quser(user);
    QString confPath = "/home/" + quser + "/.bingbg/" + "qt-config.xml";
    ui -> labelImg -> setText("...");
    ui->statusbar->showMessage(tr("---"),0);
    downloadXml();
}

void BingBG::on_actionAutoStart_toggled(bool checked)
{
    if(checked == true)
    {
        setAutoStart();
    }
    else
    {
        rmAutoStart();
    }
}
