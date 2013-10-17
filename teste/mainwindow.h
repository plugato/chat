#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "PackageBuilder.h"
#include "package.h"
#include <QPushButton>
#include "packagemensagem.h"


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Envia();

    ~MainWindow();
public slots:
    void RecebeMensagem(const QByteArray &msg);

signals:
    void SendPack( const Chat::PackageMensagem & );
   // void SendPack(  );




private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
