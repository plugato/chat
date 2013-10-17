#ifndef PACKAGEMENSAGEM_H
#define PACKAGEMENSAGEM_H
#include "package.h"



namespace Chat {


class PackageMensagem : public Package
{
public:
    PackageMensagem();


    PackageType type() const ;

    QString  Destinatario;
    QString  Mensagem;

    void SetDestinatario( const QString & );
    //QString GetDestinatario();
    QString GetDestinatario() const;

    void SetMsg(const QString & );
    QString GetMsg() const;




};





}
#endif // PACKAGEMENSAGEM_H



