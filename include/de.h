#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class DE;
}

class DE : public QWidget
{
    Q_OBJECT

public:
    explicit DE(QWidget *parent = nullptr);
    ~DE();

private:
    Ui::DE *ui;
};

#endif // SETTINGS_H
