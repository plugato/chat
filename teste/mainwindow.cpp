#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PackageBuilder.h"
#include "PackageBuilder.cpp"

#include "packagemensagem.h"
#include "package.h"
#include "socket.h"
#include <QtEndian>
#include <QHostAddress>
#include <QThread>

/*
quint32 PegaIp( const QString & ip){
      QHostAddress *ha = new QHostAddress( ip );
      return ha->toIPv4Address();
}*/

/*quint32 PegaIp( QByteArray ip ){
      QHostAddress *ha = new QHostAddress(  );
      return ha->toIPv4Address();
}*/




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



    //QThread *ThreadSocket = new QThread;

    //ThreadSocket





    //connect();
    //connect(this , &MainWindow::SendPack,   Chat::Socket::pack  ,&Chat::Socket::SendPackage  );

    //ui->lineEdit->setText(pack->GetDestinatario());
    // ui->lineEdit_2->setText(pack->GetMsg());

    //connect( s, &QTcpSocket::readyRead, this , &MainWindow::RecebeMensagem );
   // s->moveToThread(ThreadSocket);
   // ThreadSocket->start();

    ui->setupUi(this);

    Chat::Socket *s= new Chat::Socket ;

    connect(ui->pb_atualiza , &QPushButton::clicked, this, &MainWindow::Envia  );
    connect(s , &Chat::Socket::NovaMensagem, this, &MainWindow::RecebeMensagem );
    connect(this, &MainWindow::SendPack,        s, &Chat::Socket::SendPackage);




}

void MainWindow::Envia(){

    QString texto = ui->lineEdit->text();

    Chat::PackageMensagem * pack;


   // quint32 q32 = PegaIp("192.168.1.180");
    quint32 q32 = PegaIp("192.168.1.254");


    QString Msg = texto;

    uchar arraychar[4];
    qToBigEndian( q32,arraychar );//, arraychar);         //-1062731340, arraychar);

    QByteArray  q;

    q.append('\0');
    q.append( reinterpret_cast<const char *> (arraychar) , 4);
    //q.append(q32);
    uchar a[2];
    quint16 qw16 = Msg.length();
    qToBigEndian( qw16,a );

    q.append( reinterpret_cast<const char *> (a) , 2);

    q.append(texto);


    //

    pack =  static_cast< Chat::PackageMensagem * > ( Chat::PackageBuilder::buildPackage( q ));

    //

    emit SendPack( * pack );



   // Chat::Socket s ;//= new Chat::Socket;



    //ui->lineEdit->setText(pack->GetDestinatario());
    //ui->lineEdit_2->setText(pack->GetMsg());
    //Chat::Socket::SendPackage( pack );








}
void MainWindow::RecebeMensagem( const QByteArray & msg){
    ui->lineEdit_2->setText( msg );
    ui->tb->append(msg);
    qDebug("msg retorno");


}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::SendPack(QByteArray){

//}

