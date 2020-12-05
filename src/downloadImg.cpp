#include "include/download.h"
#include "include/proc.h"
#include "include/write_data.h"

int downloadImg(char *TIME_IMG, char *USRNAME)
{
  qDebug()<<"<Image: Start Downloading!!!>"<<endl;
  CURL *curlImg;
  FILE *fpImg;
  CURLcode resImg;
  char *imgName;
  char *img_url_f = parseXml(TIME_IMG, USRNAME);
  asprintf(&imgName, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_IMG, "/Wallpaper.jpg");
  qDebug()<<"Downloading Image!!!"<<endl;
  curlImg = curl_easy_init();
  if(curlImg)
  {
    fpImg = fopen(imgName, "wb");
    curl_easy_setopt(curlImg, CURLOPT_URL, img_url_f);
    curl_easy_setopt(curlImg, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curlImg, CURLOPT_WRITEDATA, fpImg);
    //curl_easy_setopt(curlImg, CURLOPT_NOPROGRESS, 0);
    resImg = curl_easy_perform(curlImg);
    fclose(fpImg);
  }
  qDebug()<<"Download Finished!!!\n"<<endl;
  qDebug()<<"The image has been stored"<<endl;
  free(imgName);
  free(img_url_f);
  return 0;
}

