#include "include/proc.h"

void makeDir(char *TIME_MD, char *USRNAME)
{
  char *folderPath;
  asprintf(&folderPath, "%s%s%s", "/home/", USRNAME, "/BBG-Download");
  //strcpy(folderPath, "/home/");
  //strcat(folderPath, USRNAME);
  //strcat(folderPath, "/BBG-Download");

  qDebug()<<"Creating work-folder...\n"<<endl;
  if (access(folderPath, 0) == -1)
  {
    mkdir(folderPath, S_IRWXO | S_IRWXU);
    qDebug()<<*folderPath<<endl;
    qDebug()<<"Successful!!!"<<endl;
  }
  else
  {
    qDebug()<<*folderPath<<endl;
    qDebug()<<"Folder is already created!!"<<endl;
  }
  free(folderPath);
  asprintf(&folderPath, "%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_MD);

  if (access(folderPath, 0) == -1)
  {
    qDebug()<<"Creating download folder..."<<endl;
    mkdir(folderPath, S_IRWXO | S_IRWXU);
    qDebug()<<*folderPath<<endl;
    qDebug()<<"Successful!!!"<<endl;
  }
  else
  {
    qDebug()<<*folderPath<<endl;
    qDebug()<<"Failed to ctreate folder the folder may be exist!!!"<<endl;
  }
  free(folderPath);
}
