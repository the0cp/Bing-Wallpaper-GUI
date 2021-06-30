/***************************************************************************
 * Author: Theodore Cooper                                                 *
 * License: GNU General Public License                                     *
 *                                                                         *
 * Bing-Backgrounds-Getter-v1.2.2                                          *
 *                                                                         *
 * Copyright (C) 2021 Theodore Cooper <ccooperr2005@gmail.com>             *
 *                                                                         *
 * This program is free software: you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ***************************************************************************/

#ifndef BINGBG_H
#define BINGBG_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QFile>​
#include <QDesktopServices>
#include <QMainWindow>
#include <QCloseEvent>
#include <QTranslator>
#include <QSettings>
#include <QMessageBox>
#include <QAbstractButton>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QLockFile>
#include "include/about.h"
#include "include/author.h"
#include "include/de.h"
#include "include/lang.h"
#include "include/proxy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BingBG; }
QT_END_NAMESPACE

class BingBG : public QMainWindow
{
    Q_OBJECT

public:
    BingBG(QWidget *parent = nullptr);

    ~BingBG();

    void autoStart();

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

    void loadLanguage(int LANGINDEX);

    void showNotifi();

    QString parseXml(char *TIME_PX, char *USRNAME);

    About *p_OpenAbout;
    Author *p_OpenAuthor;
    DE *p_OpenDE;
    LANG *p_OpenLANG;
    Proxy *p_OpenProxy;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *files;

private slots:
    void on_btnExit_clicked();

    void on_btnOpenimg_clicked();

    void openAbout();

    void openAuthor();

    void openDE();

    void openLANG();

    void openProxy();

    void on_btnFetch_clicked();

    void on_btnOpenfolder_clicked();

    void on_btnSetbg_clicked();

    int OnSystemTrayClicked(QSystemTrayIcon::ActivationReason REASON);

    void showMainwindow();

    void setAutoStart();

    void rmAutoStart();

    void checkAutoStart();

    void on_actionAutoStart_toggled(bool checked);

private:
    Ui::BingBG *ui;

    QSystemTrayIcon systray;

    QMenu *traymenu;

};
#endif // BINGBG_H
