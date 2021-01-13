#ifndef SETBG_H
#define SETBG_H


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
