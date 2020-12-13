#include "include/proc.h"

void conf(char *USRNAME)
{
    char *conFolder;
    asprintf(&conFolder, "%s%s%s", "/home/", USRNAME, "/.bingbg");

    if(access(conFolder, 0) == -1)
    {
    mkdir(conFolder, S_IRWXO | S_IRWXU);
    }
    else
    {
    qDebug()<<"Folder is already created!!"<<endl;
    }

    asprintf(&conFolder, "%s%s%s%s", "/home/", USRNAME, "/.bingbg", "/qt-config.xml");

    if(access(conFolder, 0) == -1)
    {
        xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
        xmlNodePtr root_node = xmlNewNode(NULL, BAD_CAST"root");
        xmlDocSetRootElement(doc,root_node);

        xmlNewTextChild(root_node, NULL, BAD_CAST "DeskEnvironment", BAD_CAST "NULL");

        int nRel = xmlSaveFile(conFolder, doc);
        if (nRel != -1)
        {
            qDebug()<<"config file successfully created!!!"<<endl;
        }
        xmlFreeDoc(doc);
        free(conFolder);
    }
    else
    {
        free(conFolder);
    }
}
