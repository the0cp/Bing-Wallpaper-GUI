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

void BingBG::loadLanguage(int LANGINDEX)
{
    QString qmFilename;
    QTranslator *translator = new QTranslator;
    QString runPath = QCoreApplication::applicationDirPath();
    if(LANGINDEX == 0)
    {
        qmFilename = runPath + "/translations/lang_en_US.qm";
    }
    else if (LANGINDEX == 1)
    {
        qmFilename =runPath + "/translations/lang_fr_FR.qm";
    }
    else if (LANGINDEX == 2)
    {
        qmFilename = runPath + "/translations/lang_fr_CA.qm";
    }
    else if (LANGINDEX == 3)
    {
        qmFilename = runPath + "/translations/lang_ge_GE.qm";
    }
    else if (LANGINDEX == 4)
    {
        qmFilename = runPath + "/translations/lang_ru_RU.qm";
    }
    else if (LANGINDEX == 5)
    {
        qmFilename = runPath + "/translations/lang_zh_CN.qm";
    }
    else if (LANGINDEX == 6)
    {
        qmFilename = runPath + "/translations/lang_zh_TW.qm";
    }
    if (translator->load(qmFilename))
    {
        qApp->installTranslator(translator);
    }
    ui->retranslateUi(this);
}
