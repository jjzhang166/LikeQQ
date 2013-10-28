#include "networkmonitor.h"
#include <QDebug>

NetworkMonitor::NetworkMonitor(QObject *parent) :
    QThread(parent)
{
    pnt = new QNetworkConfigurationManager(this);
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
}

NetworkMonitor::~NetworkMonitor()
{
      pnt->deleteLater();
}

void NetworkMonitor::init()
{

}

void NetworkMonitor::run()
{
    while(1)
    {       
         QList<QNetworkConfiguration> activeConfigs = pnt->allConfigurations(QNetworkConfiguration::Active);
         if(activeConfigs.count()>0)
         {
        //if(pnt->isOnline()){
            if(!Global::isOnline){
                emit signalOffline(false);
                qDebug() << "network is online";
            }
            Global::isOnline = true;
        }else
        {
            if(Global::isOnline){
                emit signalOffline(true);
                qDebug() << "network offline";
            }
            Global::isOnline = false;
        }
       // QHostInfo::lookupHost("www.nduoa.com", this, SLOT(lookedUp(QHostInfo)));
        sleep(3);
    }
}

void NetworkMonitor::lookedUp(QHostInfo host)
{   
    qDebug() << "wo cao ni mamamamamammamamamamam" << Global::isOnline << "host.error():" << host.error() ;
    if (host.error() != QHostInfo::NoError)
    {
        qDebug() << "wo cao ni mamamamamammamamamamam" << Global::isOnline;
        if(Global::isOnline){
            emit signalOffline(false);
        }
        Global::isOnline = false;
    }
    else
    {       
        Global::isOnline = true;
    }
}
