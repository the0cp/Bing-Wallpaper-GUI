#ifndef LANG_H
#define LANG_H

#include <QDialog>
#include <QDebug>
#include <QAbstractButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QSettings>
#include <QCloseEvent>
#include <QMessageBox>

namespace Ui {
class LANG;
}

class LANG : public QDialog
{
    Q_OBJECT

public:
    explicit LANG(QWidget *parent = nullptr);
    ~LANG();

    void checkLang();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::LANG *ui;
    QButtonGroup *groupButton;
};

#endif // LANG_H
