#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;

}
int arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serial_port_info.hasProductIdentifier() && serial_port_info.hasVendorIdentifier()){
        //  check if the product ID and the vendor ID match those of the arduino uno
            if(serial_port_info.productIdentifier() == arduino_uno_product_id && serial_port_info.vendorIdentifier() == arduino_uno_vendor_id){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_port_name = serial_port_info.portName();
            }
        }
    }
    qDebug()<<"Arduino Port Name is:"<<arduino_port_name;

    //  Open and configure the arduino port if available

    if(arduino_is_available)
    {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        return 0;
        }
        return 1;
    }
    return -1;
}
int arduino::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;

}
QByteArray arduino::read_from_arduino()
{
    if(serial->isReadable())
    {
        data=serial->readAll();
        return data;
    }
            return data;
}
int arduino::write_to_arduino(QByteArray d)
{
    if(serial->isWritable())
    {
        serial->write(d);
    }
    else
    {
        qDebug()<< "couldn't write to serial!";
    }
}
