#include "listen.h"
#include "socket.h"
#include <QTcpSocket>



namespace Chat {
listen::listen()
{
    socket = new QTcpSocket;



}

void listen::listening(){
    socket->connectToHost("192.168.1.254",667);
    socket->write("9999999");
    qDebug("s");
}

}
