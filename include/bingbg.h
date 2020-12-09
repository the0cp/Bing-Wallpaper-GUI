#ifndef BINGBG_H
#define BINGBG_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QFile>​
#include <QMainWindow>
#include "include/about.h"
#include "include/author.h"
#include "include/exitconfirmation.h"


QT_BEGIN_NAMESPACE
namespace Ui { class BingBG; }
QT_END_NAMESPACE

class BingBG : public QMainWindow
{
    Q_OBJECT

public:
    BingBG(QWidget *parent = nullptr);
    ~BingBG();
    void initDownload();

    void download(QString URL, QString PATH);

    void doProcessReadyRead();

    void doProcessFinished();

    void doProcessDownloadProgress(qint64,qint64);

    void doProcessError(QNetworkReply::NetworkError code);

    About *p_OpenAbout;
    Author *p_OpenAuthor;
    exitConfirmation *p_confirm;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *files;

private slots:
    void on_btnExit_clicked();

    void on_btnOpenimg_clicked();

    void openAbout();

    void openAuthor();

    void on_btnFetch_clicked();

private:
    Ui::BingBG *ui;
};
#endif // BINGBG_H
