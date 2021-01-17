#ifndef PROC_H
#define PROC_H

//#define _GNU_SOURCE


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <libxml/tree.h>
#include <libxml/parser.h>

extern char *geTime();
extern char *readConf();
extern void makeDir(char *TIME_MD, char *USRNAME);

extern void conf(char *USRNAME);
#endif // PROC_H
