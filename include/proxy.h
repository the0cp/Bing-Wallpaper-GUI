#ifndef PROXY_H
#define PROXY_H

#include <QDialog>
#include <QButtonGroup>
#include <QNetworkProxy>
#include <QNetworkProxyQuery>
#include <QAbstractButton>
#include <QButtonGroup>
#include <QMessageBox>
#include <QPushButton>
#include <QSettings>

namespace Ui {
class Proxy;
}

class Proxy : public QDialog
{
    Q_OBJECT

public:
    explicit Proxy(QWidget *parent = nullptr);
    ~Proxy();

    void setProxy();

    void writeState();

    void readState();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_rbtn_manual_clicked(bool checked);

    void on_rbtn_sys_clicked(bool checked);

    void on_rbtn_noproxy_clicked(bool checked);

private:
    Ui::Proxy *ui;
    QButtonGroup *groupButton;
};

#endif // PROXY_H
