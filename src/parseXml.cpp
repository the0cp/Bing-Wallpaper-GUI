#include "include/proc.h"

char *parseXml(char *TIME_PX, char *USRNAME)
{
	char *img_url;
    xmlChar *urlPart;
  	char *xmlName;
  	asprintf(&xmlName, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_PX, "/index.xml");
  	xmlDocPtr pdoc = NULL;
  	xmlNodePtr proot = NULL;
  	xmlNodePtr pcur = NULL;
  
  	xmlKeepBlanksDefault(0); //Blanks may be parse as a node
  	pdoc = xmlReadFile(xmlName, "UTF-8", XML_PARSE_RECOVER);

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
    	if (!xmlStrcmp(pcur->name, BAD_CAST("image")))
    	{
      		xmlNodePtr nptr=pcur->xmlChildrenNode;
      		while (pcur != NULL)
      		{
        		if (!xmlStrcmp(nptr->name, BAD_CAST("url")))
        		{       
                    urlPart = XML_GET_CONTENT(nptr->xmlChildrenNode);
                    asprintf(&img_url, "%s%s", "https://www.bing.com", urlPart);
          			break;
        		}
        	nptr = nptr -> next;
      		}
    	}
    	pcur = pcur -> next;
  	}

  	xmlFreeDoc(pdoc);
  	xmlCleanupParser();
  	xmlMemoryDump();
    qDebug()<<"<Parse Done!!!>"<<endl;
	return img_url;
	
}
