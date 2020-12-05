#ifndef BINGBG_H
#define BINGBG_H

#include <QMainWindow>
#include "include/about.h"


QT_BEGIN_NAMESPACE
namespace Ui { class BingBG; }
QT_END_NAMESPACE

class BingBG : public QMainWindow
{
    Q_OBJECT

public:
    BingBG(QWidget *parent = nullptr);
    ~BingBG();
    About *p_OpenAbout;

private slots:
    void on_btnExit_clicked();

    void on_btnOpenimg_clicked();

    void openAbout();

    void on_btnFetch_clicked();

private:
    Ui::BingBG *ui;
};
#endif // BINGBG_H
