#include"ModbusClient.h"

ModbusClient::ModbusClient():TCPClient()
{

}

uint8_t ModbusClient::ReadSingleCoil()
{
    //Vytvorenie Hlavicky mbap pre modbus spojenie 
    //transaction id su 2 byte ktorym sa identifikuje ukon
    
}