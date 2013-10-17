#include "waitmensage.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "servertcp.h"



WaitMensage::WaitMensage()
{


}



void WaitMensage::WaitMsg(){

     //tcpServer = new QTcpServer;
    // tcpServer->listen( QHostAddress::Any,3300 );
     ServerTcp Tcp;
     qDebug("errado");
     qDebug(Tcp.tcpSockt->readAll());




     //emit EnviaMsg( Msg.toLocal8Bit());


}

