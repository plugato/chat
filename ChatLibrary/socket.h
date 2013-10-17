#ifndef CHAT_SOCKET_H
#define CHAT_SOCKET_H
#include <QByteArray>
#include "package.h"
#include "PackageBuilder.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include "waitmensage.h"
#include "servertcp.h"



namespace Chat {

class Socket : public QObject
{
    Q_OBJECT

public:
    Socket();

    QThread *thread;

    QTcpServer *tcpServer;


    QTcpSocket *socket;  // = new QTcpSocket ;



    ServerTcp   *server;
    WaitMensage *waitMsg;

    QThread *serverThread;
    QThread *AguardarMensagem;


private:
public slots:
    Package * GetPackage();
    QString SendPackage(const PackageMensagem &data );
    void click();
    void Atualiza( const QByteArray & );
signals:
    void Clicked( const QByteArray &);
    void NovaMensagem(const QByteArray &  );
     //void SendPack( const PackageMensagem & );


};


} // namespace Chat
#endif // CHAT_SOCKET_H
