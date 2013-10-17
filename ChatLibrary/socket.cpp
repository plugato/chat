#include "socket.h"
#include "receive.h"
#include "PackageBuilder.h"
#include <QtEndian>
#include <QTcpSocket>
#include <QTcpServer>

#include <QThread>



namespace Chat {
Socket::Socket()
{

    socket = new QTcpSocket ;
    tcpServer = new QTcpServer;
    //QTcpSocket *tcp = new QTcpSocket;

    //thread = new QThread;

    //tcpServer->listen( QHostAddress::Any , 666);
    serverThread = new QThread;
    AguardarMensagem = new QThread;

    server = new ServerTcp;
    waitMsg = new WaitMensage;


    server->moveToThread(serverThread);
    waitMsg->moveToThread(AguardarMensagem);



    serverThread->start();
    AguardarMensagem->start();



    //connect( q, &QPushButton::clicked, this, &MainWindow::click);

    connect( socket, &QTcpSocket::readyRead, this, &Socket::click);
    connect( this, &Socket::Clicked, server, &ServerTcp::servertcp );
    connect( server, &ServerTcp::EnviaMsg, this, &Socket::Atualiza );


    //connect( tcpServer, &QTcpServer::newConnection, this, &Chat::listen::listening);
    connect( tcpServer, &QTcpServer::newConnection, this, &Chat::Socket::GetPackage  );
    //connect( socket, &QTcpSocket::readyRead, this , &MainWindow::RecebeMensagem );
    //socket->connectToHost("192.168.1.180",666);

    //socket = QTcpServer::nextPendingConnection();





    //connect( socket, &QTcpSocket::readyRead, this, &Chat::Socket::GetPackage  );

    //receive *rec = new receive;


    //tcp->connectToHost("192.168.1.180",666);

    //connect( list->tcpServer, &QTcpServer::newConnection, this, &Chat::Socket::GetPackage  );
    //connect( tcp, &QTcpSocket::readyRead, rec , &Chat::receive::Receiver);//&Chat::Socket::GetPackage  );

    //socket->moveToThread(thread);
    //tcp->moveToThread( thread);
   // tcpServer->moveToThread(thread);
   // thread->start();




    //socket->moveToThread(thread);
      // thread->start();
    //connect(this, &Chat::Socket::SendPack,   this, &Chat::Socket::SendPackage);
}



void Socket::Atualiza(const QByteArray & Msg){
    qDebug(" Msg" );
    qDebug( Msg );
}

void Socket::click(){
    QByteArray Msg = socket->readAll() ;
    qDebug("pegar retorno");
    emit Clicked( Msg );
}



QString Socket::SendPackage(const PackageMensagem &data ){


    qDebug("send");



    if( !socket->isOpen() )
         socket->connectToHost(data.Destinatario,667); //voltar isso


    const QByteArray aa = Chat::PackageBuilder::unbuildPackage(& data);


    socket->write( aa );
    qDebug("send package");
    qDebug(aa);
    return aa;
}

Package *Socket::GetPackage(  ){
  //  socket->connectToHost(QTcpServer::serverAddress());

    //PackageMensagem packmsg ;//= new PackageMensagem;

    //QByteArray q = socket->readAll();

   // li->moveToThread(thread);
    //connect( tcpServer, &QTcpServer::newConnection, li, &Chat::listen::listening);

    //thread->start();

    //li->socket->write("aasdfasdf");






    qDebug("funwfo");

     QByteArray bytea = "aaa";

     //if( socket->waitForReadyRead(10000)){
         //bytea = li->socket->readAll();
     //}

    Chat::PackageMensagem * unpack ;

    unpack = static_cast< Chat::PackageMensagem * > ( Chat::PackageBuilder::buildPackage( bytea ));

    SendPackage( *unpack );
    QByteArray unpackByteArray = Chat::PackageBuilder::unbuildPackage( unpack );

    emit NovaMensagem( unpackByteArray );

    return unpack;


}




} // namespace Chat
