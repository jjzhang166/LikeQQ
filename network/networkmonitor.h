#ifndef NETWORKMONITOR_H
#define NETWORKMONITOR_H

#include <QObject>
#include <QThread>
#include <QNetworkConfigurationManager>
#include <QTcpSocket>
#include <QHostInfo>
#include "global/global.h"


class NetworkMonitor : public QThread
{
    Q_OBJECT
public:
    explicit NetworkMonitor(QObject *parent = 0);
    ~NetworkMonitor();
    
protected:
    void run();

public:
    void init();
signals:
    void signalOffline(bool);
private:
    QNetworkConfigurationManager* pnt;

private slots:
    void lookedUp(QHostInfo host);
};

#endif // NETWORKMONITOR_H
