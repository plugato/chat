#ifndef RECEIVE_H
#define RECEIVE_H
#include "QTcpSocket"

#include <QObject>


namespace Chat {

class receive : public QObject
{
    Q_OBJECT


public:
    receive();
    QTcpSocket *e;
public slots:
    void Receiver();

};

}
#endif // RECEIVE_H
