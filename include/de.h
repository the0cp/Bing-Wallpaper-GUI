#ifndef DE_H
#define DE_H

#include <QDialog>
#include <QDebug>
#include <QAbstractButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QSettings>
#include <QCloseEvent>
#include <QMessageBox>

namespace Ui {
class DE;
}

class DE : public QDialog
{
    Q_OBJECT

public:
    explicit DE(QWidget *parent = nullptr);
    ~DE();

    void checkDE();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::DE *ui;
    QButtonGroup *groupButton;
};

#endif // DE_H
