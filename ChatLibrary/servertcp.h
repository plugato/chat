#ifndef SERVERTCP_H
#define SERVERTCP_H
#include <QTcpServer>
#include <QTcpSocket>

class ServerTcp :  public QObject
{
    Q_OBJECT
public:
    ServerTcp();
    QTcpServer *tcpServer;
    QTcpSocket *tcpSockt;

public slots:
    void servertcp(const QByteArray & );
signals:
    void EnviaMsg( const QByteArray & );


};

#endif // SERVERTCP_H
