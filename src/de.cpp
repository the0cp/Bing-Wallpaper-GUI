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

#include "include/de.h"
#include "include/proc.h"
#include "ui_de.h"

DE::DE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DE)
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    ui->setupUi(this);
    groupButton=new QButtonGroup(this);
    groupButton -> addButton(ui -> rbtn_mate, 0);
    groupButton -> addButton(ui -> rbtn_xfce, 1);
    groupButton -> addButton(ui -> rbtn_gnome, 2);
    groupButton -> addButton(ui -> rbtn_cinn, 3);

    groupButton->button(settings.value("DesktopEnvironment/default").toInt())->setChecked(true);
}

DE::~DE()
{
    delete ui;
}

void DE::checkDE()
{
    char *time = geTime();
    char *user = getlogin();
    QString qtime(time);
    QString quser(user);
    QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
    QSettings settings(qconfPath, QSettings::IniFormat);
    switch(groupButton->checkedId())
    {
        case 0:
            settings.setValue("DesktopEnvironment/default", 0);
            break;
        case 1:
            settings.setValue("DesktopEnvironment/default", 1);
            break;
        case 2:
            settings.setValue("DesktopEnvironment/default", 2);
            break;
        case 3:
            settings.setValue("DesktopEnvironment/default", 3);
            break;
        default:
            break;
    }
}

void DE::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok)  == button)
    {
        checkDE();
    }
    else
    {
        reject();
    }
}
