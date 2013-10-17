#include "receive.h"
#include "socket.h"


namespace Chat {


receive::receive()
{




     e = new QTcpSocket;
     e->connectToHost("192.168.1.180",666);

}



void receive::Receiver(  ){

    qDebug("ssss");



}














}
