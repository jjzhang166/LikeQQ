#include "datainterface.h"
#include <QFileDialog>

DataInterface::DataInterface(QObject *parent) :
    QObject(parent),isConnected(false)
{
    creatConnection();
}

void DataInterface::slotRequestData(int cmd, QStringList parameterList)
{
   MainWidgetUI::instance()->requestData(cmd,parameterList);
}

void DataInterface::slotResponseNotifyUI(bool error, int cmd, QStringList processResult)
{ 
    MainWidgetUI::instance()->responseNotifyUI(error,cmd,processResult);
}

//=======================creat connection in first request(connection depdent instance)==========================
void DataInterface::creatConnection()
{
      connect(MainWidgetUI::instance(),SIGNAL(signalNotifyUI(bool,int,QStringList)),this,SIGNAL(signalNotifyUI(bool,int,QStringList)));
      connect(MainWidgetUI::instance(),SIGNAL(signalResponseDataReady(bool,int,QStringList)),this,SIGNAL(signalResponseDataReady(bool,int,QStringList)));
}

//改变鼠标的样式
void DataInterface::slotChangeCursor(int flag)
{
    switch(flag){
    case 0:
    {
        MainWidgetUI::instance()->setCursor(QCursor(Qt::ArrowCursor));}
        break;
    case 1:
    {
        MainWidgetUI::instance()->setCursor(QCursor(Qt::PointingHandCursor));}
        break;
    case 2:
    {
        MainWidgetUI::instance()->setCursor(QCursor(Qt::SplitHCursor));}
        break;
    default:
        break;
    }
}









