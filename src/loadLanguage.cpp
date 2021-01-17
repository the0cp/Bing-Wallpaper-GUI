#include "include/bingbg.h"
#include "ui_bingbg.h"

void BingBG::loadLanguage(int LANGINDEX)
{
    QString qmFilename;
    QTranslator *translator = new QTranslator;
    QString runPath = QCoreApplication::applicationDirPath();
    if(LANGINDEX == 0)
    {
        qmFilename = runPath + "/translations/lang_en_US.qm";
    }
    else if (LANGINDEX == 1)
    {
        qmFilename =runPath + "/translations/lang_fr_FR.qm";
    }
    else if (LANGINDEX == 2)
    {
        qmFilename = runPath + "/translations/lang_fr_CA.qm";
    }
    else if (LANGINDEX == 3)
    {
        qmFilename = runPath + "/translations/lang_ge_GE.qm";
    }
    else if (LANGINDEX == 4)
    {
        qmFilename = runPath + "/translations/lang_ru_RU.qm";
    }
    else if (LANGINDEX == 5)
    {
        qmFilename = runPath + "/translations/lang_zh_CN.qm";
    }
    else if (LANGINDEX == 6)
    {
        qmFilename = runPath + "/translations/lang_zh_TW.qm";
    }
    if (translator->load(qmFilename))
    {
        qApp->installTranslator(translator);
    }
    ui->retranslateUi(this);
}
