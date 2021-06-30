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

#include "include/setbg.h"
#include "include/proc.h"

setBG::setBG()
{

}

void setBG::setBG_MATE(char *TIME, char *USRNAME)
{
    char *mate_com;
    char *picUri;
    pid_t status;
    asprintf(&picUri, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME, "/Wallpaper.jpg");
    asprintf(&mate_com, "%s%s%s%s", "gsettings set org.mate.background picture-filename ", "\"", picUri, "\"");
    status = system(mate_com);
    if(status == -1)
    {
        printf("error");
    }
    else
    {
        if(WIFEXITED(status))
        {
            if(WEXITSTATUS(status) == 0)
            {
                printf("done");
            }
            else
            {
                printf("error");
            }
        }
        else
        {
            printf("error");
        }
    }
    free(mate_com);
    free(picUri);
}

void setBG::setBG_GNOME(char *TIME, char *USRNAME)
{
    char *gnome_com;
    char *picUri;
    pid_t status;
    asprintf(&picUri, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME, "/Wallpaper.jpg");
    asprintf(&gnome_com, "%s%s%s%s", "gsettings set org.gnome.desktop.background picture-uri ", "\"", picUri, "\"");
    status = system(gnome_com);
    if(status == -1)
    {
        printf("error");
    }
    else
    {
        if(WIFEXITED(status))
        {
            if(WEXITSTATUS(status) == 0)
            {
                printf("done");
            }
            else
            {
                printf("error");
            }
        }
        else
        {
            printf("error");
        }
    }
    free(gnome_com);
    free(picUri);
}

void setBG::setBG_XFCE(char *TIME, char *USRNAME)
{
    char *xfce_com;
    char *picUri;
    pid_t status;
    asprintf(&picUri, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME, "/Wallpaper.jpg");
    asprintf(&xfce_com, "%s%s%s%s", "xfconf-query -c xfce4-desktop -p /backdrop/screen0/monitor0/workspace0/last-image -s ", "\"", picUri, "\"");
    status = system(xfce_com);
    if(status == -1)
    {
        printf("error");
    }
    else
    {
        if(WIFEXITED(status))
        {
            if(WEXITSTATUS(status) == 0)
            {
                printf("done");
            }
            else
            {
                printf("error");
            }
        }
        else
        {
            printf("error");
        }
    }
    free(xfce_com);
    free(picUri);
}

void setBG::setBG_CINNAMON(char *TIME, char *USRNAME)
{
    char *cinn_com;
    char *picUri;
    pid_t status;
    asprintf(&picUri, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME, "/Wallpaper.jpg");
    asprintf(&cinn_com, "%s%s%s%s", "gsettings set org.cinnamon.desktop.background picture-uri ", "\"", picUri, "\"");
    status = system(cinn_com);
    if(status == -1)
    {
        printf("error");
    }
    else
    {
        if(WIFEXITED(status))
        {
            if(WEXITSTATUS(status) == 0)
            {
                printf("done");
            }
            else
            {
                printf("error");
            }
        }
        else
        {
            printf("error");
        }
    }
    free(cinn_com);
    free(picUri);
}
