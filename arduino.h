#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QByteArray>
#include <QMessageBox>


class arduino
{
public:
    arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort * getserial(){return serial;}
    QString getarduino_port_name(){return arduino_port_name;}

private:
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray data;
    bool arduino_is_available;
    QString arduino_port_name;


};

#endif // ARDUINO_H
