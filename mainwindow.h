#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void UpdatePorts();

private slots:
    void on_btn_Port_clicked();

    void on_btn_EnviarValores_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *_serialPort;
};
#endif // MAINWINDOW_H
