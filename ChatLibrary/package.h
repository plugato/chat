#ifndef CHAT_PACKAGE_H
#define CHAT_PACKAGE_H
#include <QObject>



namespace Chat {

class Package
{

public:
    Package();

enum PackageType{
    Msg,
    Version

};

virtual PackageType type() const = 0;

};



} // namespace Chat
#endif // CHAT_PACKAGE_H
