#include "include/proc.h"

char *readConf()
{
    xmlDocPtr pdoc = NULL;
    xmlNodePtr proot = NULL;
    xmlNodePtr pcur = NULL;

    char *dEnv;
    char *configFile;
    asprintf(&configFile, "%s%s%s%s", "/home/", getlogin(), "/.bingbg", "/qt-config.xml");

    xmlKeepBlanksDefault(0); //Blanks may be parse as a node
    pdoc = xmlReadFile(configFile, "UTF-8", XML_PARSE_RECOVER);

    if (pdoc == NULL)
    {
        qDebug()<<"ERROR:cannot open xml!!!"<<endl;
        return NULL;
    }

    proot = xmlDocGetRootElement(pdoc);

    if(proot == NULL)
    {
        qDebug()<<"ERROR: Xml is empty!!!"<<endl;
        return NULL;
    }

    pcur = proot -> xmlChildrenNode;

    while (pcur != NULL)
    {
        if (!xmlStrcmp(pcur->name, BAD_CAST("DeskEnvironment")))
        {
            xmlNodePtr nptr=pcur->xmlChildrenNode;
            if(*(XML_GET_CONTENT(nptr)) == *("NULL"))
            {

                //asprintf(&dEnv, "%s", setDE());
                //const xmlChar *setCont = dEnv;
                //xmlNodeSetContent(pcur, setCont);
                /*
                int nRel = xmlSaveFile(configFile, pdoc);
                if (nRel != -1)
                {
                    printf("config file saved!!!\n");
                }*/
                break;
            }
            else
            {
                asprintf(&dEnv, "%s", XML_GET_CONTENT(nptr));
                break;
            }
            break;
        }
        pcur = pcur -> next;
    }
    xmlFreeDoc(pdoc);
    xmlCleanupParser();
    xmlMemoryDump();
    free(configFile);
    return dEnv;
}
