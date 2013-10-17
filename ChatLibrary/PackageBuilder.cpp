#include "package.h"
#include "PackageBuilder.h"
#include "packagemensagem.h"
#include <QtEndian>
#include <QHostAddress>
#include <QtEndian>

quint32 PegaIp( const QString & ip){
      QHostAddress *ha = new QHostAddress( ip );
      return ha->toIPv4Address();
}


QString DevolveIp( const quint32& ip){
      QHostAddress *ha = new QHostAddress( ip );
      return ha->toString();
}

namespace Chat {

PackageBuilder::PackageBuilder()
{

}


Package * PackageBuilder::buildPackage( const QByteArray & data  ){

    if( data[ 0 ] == Package::Msg )
        return buildMsgPackage( data.right(data.length() - 1));

   // if( data[ 0 ] == Package::Version )
   //     return buildMsgPackage( data.right(5 ));
    return buildMsgPackage( data.right(data.length() ));

}

PackageMensagem * PackageBuilder::buildMsgPackage(const QByteArray & data ){
    //uchar charTamanho[2];
    //qint16 intTamanho;
    //intTamanho = qFromBigEndian( *charTamanho );

    PackageMensagem  *pm = new PackageMensagem;

    quint32 e = qFromBigEndian <quint32>( reinterpret_cast <const uchar * >(data.left(4).constData()) );

    QHostAddress *ip = new QHostAddress( e );

    pm->SetDestinatario(   ip->toString() );
    pm->SetMsg( data.right( data.length() -5));

    //qDebug(data.right( data.length() -4));

    return pm;

}

/******************************************************************************************/

QByteArray PackageBuilder::unbuildPackage( const PackageMensagem  *data ){



     uchar arraychar[4];
     uchar arrayip[4];

     QByteArray bamensagem =  data->GetMsg().toUtf8();
     quint32 ip = PegaIp( data->Destinatario );

     qToBigEndian( bamensagem, arraychar );
     qToBigEndian( ip ,arrayip );

     QByteArray a;
     a.append( reinterpret_cast <const char * > ( data->type()  ));
     a.append( reinterpret_cast <const char * > ( arrayip  ) , 4);
     //a.append( reinterpret_cast <const char * > ( arrayip  ) , 4);
     a.append( reinterpret_cast <const char * > ( arraychar) , 4);
     a.append( bamensagem );



     return a;
    // qDebug(a);

    //data.Destinatario sobrecarga unbuild


   // pack =  static_cast< Chat::PackageMensagem * > (  data );



}

}
