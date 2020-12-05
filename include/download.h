#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <curl/curl.h>

extern void downloadXml(char *TIME_XML, char *USRNAME);
extern int downloadImg(char *TIME_IMG, char *USRNAME);

#endif // DOWNLOAD_H
