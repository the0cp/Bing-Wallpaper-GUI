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
