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

#include "include/bingbg.h"
#include "ui_bingbg.h"
#include "include/proc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    char *time = geTime();
    char *user = getlogin();
    char *confPath;
    asprintf(&confPath, "%s%s%s", "/home/", user, "/.bingbg/qt-config.ini");
    if(access(confPath, 0) == -1)
    {
        QString qtime(time);
        QString quser(user);
        QString qconfPath = "/home/" + quser + "/.bingbg/qt-config.ini";
        QSettings settings(qconfPath, QSettings::IniFormat);
        settings.setValue("DesktopEnvironment/default", -1);
    }
    BingBG w;
    w.show();
    return a.exec();
}
