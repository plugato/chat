
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "servertcp.h"
#include "waitmensage.h"

ServerTcp::ServerTcp()
{


}


void ServerTcp::servertcp(const QByteArray & Msg ){

    tcpServer = new QTcpServer;
    tcpServer->listen( QHostAddress::Any,666 );

    if(tcpServer->waitForNewConnection(10000)){
        tcpSockt = tcpServer->nextPendingConnection();
    }

    tcpSockt->write( Msg );
    emit EnviaMsg( Msg );


}
