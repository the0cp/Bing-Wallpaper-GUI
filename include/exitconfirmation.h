#ifndef EXITCONFIRMATION_H
#define EXITCONFIRMATION_H

#include <QDialog>

namespace Ui {
class exitConfirmation;
}

class exitConfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit exitConfirmation(QWidget *parent = nullptr);
    ~exitConfirmation();

private slots:

    void on_btnExit_clicked();

private:
    Ui::exitConfirmation *ui;
};

#endif // EXITCONFIRMATION_H
