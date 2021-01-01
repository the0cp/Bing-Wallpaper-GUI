#ifndef BINGBG_H
#define BINGBG_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QFile>​
#include <QDesktopServices>
#include <QMainWindow>
#include <QCloseEvent>
#include <QSettings>
#include <QMessageBox>
#include <QAbstractButton>
#include "include/about.h"
#include "include/author.h"
#include "include/de.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BingBG; }
QT_END_NAMESPACE

class BingBG : public QMainWindow
{
    Q_OBJECT

public:
    BingBG(QWidget *parent = nullptr);

    ~BingBG();

    void writeState();

    void readState();

    void closeEvent(QCloseEvent *event);

    void initDownload();

    void doProcessReadyRead();

    void doProcessFinished();

    void enableBtn();

    void doProcessDownloadProgress(qint64,qint64);

    void doProcessError(QNetworkReply::NetworkError code);

    void core_downloadXml(QString URL, QString PATH);

    void downloadXml();

    void core_downloadImg(QString URL, QString PATH);

    void downloadImg();

    void showImg();

    void setBG();

    About *p_OpenAbout;
    Author *p_OpenAuthor;
    DE *p_OpenDE;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *files;

private slots:
    void on_btnExit_clicked();

    void on_btnOpenimg_clicked();

    void openAbout();

    void openAuthor();

    void openDE();

    void on_btnFetch_clicked();

    void on_btnOpenfolder_clicked();

private:
    Ui::BingBG *ui;
};
#endif // BINGBG_H
