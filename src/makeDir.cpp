#include "include/proc.h"

void makeDir(char *TIME_MD, char *USRNAME)
{
  char *folderPath;
  asprintf(&folderPath, "%s%s%s", "/home/", USRNAME, "/BBG-Download");
  //strcpy(folderPath, "/home/");
  //strcat(folderPath, USRNAME);
  //strcat(folderPath, "/BBG-Download");

  if (access(folderPath, 0) == -1)
  {
    mkdir(folderPath, S_IRWXO | S_IRWXU);
  }
  free(folderPath);
  asprintf(&folderPath, "%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_MD);

  if (access(folderPath, 0) == -1)
  {
    mkdir(folderPath, S_IRWXO | S_IRWXU);
  }
  free(folderPath);
}
