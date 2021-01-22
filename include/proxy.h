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

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Proxy *ui;
    QButtonGroup *groupButton;
};

#endif // PROXY_H
