/***************************************************************************
 * Author: Theodore Cooper                                                 *
 * License: GNU General Public License                                     *
 *                                                                         *
 * Bing-Backgrounds-Getter-v1.2.2                                          *
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

#include "include/bingbg.h"
#include "include/proc.h"
#include "ui_bingbg.h"

QString BingBG::parseXml(char *TIME_PX, char *USRNAME)
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
        return NULL;
  	}

  	proot = xmlDocGetRootElement(pdoc);

  	if(proot == NULL)
  	{
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
    QString q_imgUrl(img_url);
    return q_imgUrl;
	
}
