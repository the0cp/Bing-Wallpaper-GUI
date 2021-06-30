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

#ifndef DE_H
#define DE_H

#include <QDialog>
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
