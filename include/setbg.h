/***************************************************************************
 * Author: Theodore Cooper                                                 *
 * License: GNU General Public License                                     *
 *                                                                         *
 * Bing-Backgrounds-Getter-v1.1.4                                          *
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

#ifndef SETBG_H
#define SETBG_H

#include <QMessageBox>
#include <QCloseEvent>
#include <QTranslator>
#include <QAbstractButton>
#include "include/bingbg.h"

class setBG
{

public:
    setBG();

    static void setBG_MATE(char *TIME, char *USRNAME);

    static void setBG_GNOME(char *TIME, char *USRNAME);

    static void setBG_XFCE(char *TIME, char *USRNAME);

    static void setBG_CINNAMON(char *TIME, char *USRNAME);
};

#endif // SETBG_H
