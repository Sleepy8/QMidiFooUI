#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _serialPort(nullptr)
{
    ui->setupUi(this);
    UpdatePorts();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::UpdatePorts(){
    foreach(auto &port, QSerialPortInfo::availablePorts()){
        ui->cb_port->addItem(port.portName());
    }
    for(int i = 0; i < 20; i++){
        QString b = QString::number(i);
        ui->cb_Valores->addItem(b);

    }
}

void MainWindow::on_btn_Port_clicked()
{
    if(_serialPort != nullptr){
        _serialPort->close();
        delete _serialPort;
    }
    _serialPort = new QSerialPort;
    _serialPort->setPortName(ui->cb_port->currentText());
    _serialPort->setBaudRate(QSerialPort::Baud9600);
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setDataBits(QSerialPort::Data8);
    _serialPort->setStopBits(QSerialPort::OneStop);
    if(_serialPort->open(QIODevice::ReadWrite)){
        QMessageBox::information(this, "Porta Aberta", "Porta aberta com sucesso");
    }else{
        QMessageBox::critical(this, "Port Error", "Erro ao abrir a porta especificada");
    }
}


void MainWindow::on_btn_EnviarValores_clicked()
{
    if(!_serialPort->isOpen()){
       QMessageBox::critical(this, "Port Error", "Erro ao abrir a porta especificada");
        return;

    }else{
        _serialPort->write(ui->cb_Valores->currentText().toUtf8());

        QMessageBox::information(this, "Porta Aberta","Mensagem Enviada: " + ui->cb_Valores->currentText()  );

    }
}

