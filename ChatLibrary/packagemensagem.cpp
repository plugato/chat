#include "packagemensagem.h"
#include "package.h"
#include "PackageBuilder.h"



namespace Chat {


PackageMensagem::PackageMensagem()
{
}


void PackageMensagem::SetDestinatario(const QString & dest){
    Destinatario = dest  ;
}

QString PackageMensagem::GetDestinatario() const{
    return Destinatario;
}

QString PackageMensagem::GetMsg() const{
    return Mensagem;
}

void PackageMensagem::SetMsg(const QString & mensagem){
    Mensagem = mensagem;
}

Package::PackageType PackageMensagem::type() const {
    return Package::Msg;
}

}
