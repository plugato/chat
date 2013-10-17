
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    
    socket = new QTcpSocket;
    
    socket->connectToHost();
    
    
    
    
    
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
