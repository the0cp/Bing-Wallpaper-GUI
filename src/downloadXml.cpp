#include "../include/download.h"
#include "../include/proc.h"
#include "../include/write_data.h"

void downloadXml(char *TIME_XML, char *USRNAME)
{
  char *xml_url;
  asprintf(&xml_url, "%s", "https://www.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1&mkt=en-US");
  qDebug()<<"<XML: Start downloading!!!>"<<endl;
  CURL *curlXml;
  FILE *fpXml;
  CURLcode resXml;
  char *xmlName;
  asprintf(&xmlName, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_XML, "/index.xml");
  qDebug()<<"Downloading Xml!!!"<<endl;
  curlXml = curl_easy_init();
  if (curlXml)
  {
    fpXml = fopen(xmlName, "wb");
    curl_easy_setopt(curlXml, CURLOPT_URL, xml_url);
    curl_easy_setopt(curlXml, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curlXml, CURLOPT_WRITEDATA, fpXml);
    curl_easy_setopt(curlXml, CURLOPT_PROGRESSFUNCTION, downloadCallback);
    curl_easy_setopt(curlXml, CURLOPT_PROGRESSDATA,NULL);
    curl_easy_setopt (curlXml, CURLOPT_NOPROGRESS, FALSE);
    resXml = curl_easy_perform(curlXml);
    curl_easy_cleanup(curlXml);
    fclose(fpXml);
  }
  free(xml_url);
  free(xmlName);
}
