#ifndef PACKAGEBUILDER_H
#define PACKAGEBUILDER_H
#include "package.h"
#include "packagemensagem.h"



namespace Chat {


class PackageBuilder
{
public:
     PackageBuilder();




     static Package *  buildPackage(   const QByteArray &data  );
     static QByteArray unbuildPackage( const PackageMensagem *   );
private:
     static QString IpDestino;
     static QString Mensagem;

     static PackageMensagem * buildMsgPackage(const QByteArray &);

private:

};


}
#endif // PACKAGEBUILDER_H


