#ifndef WAITMENSAGE_H
#define WAITMENSAGE_H
#include <QTcpServer>
#include <QTcpSocket>

class WaitMensage : public QObject
{
    Q_OBJECT
public:
    WaitMensage();
//    QTcpServer *tcpServer;
   // QTcpSocket *tcpSockt;
    void WaitMsg();
};

#endif // WAITMENSAGE_H
