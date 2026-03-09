#include"ModbusClient.h"

ModbusClient::ModbusClient():TCPClient(),ModbusHead(0,1)
{

}

uint8_t ModbusClient::ReadSingleCoil()
{
    //Vytvorenie Hlavicky mbap pre modbus spojenie 
    //transaction id su 2 byte ktorym sa identifikuje ukon
    return 0;
}

void ModbusClient::WriteSingleCoil(const bool &Data,const uint16_t &Adress)
{
     ModbusHead.Lenght = 6;
     PDUHead.FunctionCode = 5;
     PDUHead.Adress = Adress;
     PDUHead.Quantity = 1;
     std::vector<uint8_t> SendMAp;
     SendMAp = ModbusHead.BuildMap();
     SendMAp.insert(SendMAp.end(),PDUHead.PDUMap().begin(),PDUHead.PDUMap().end());
     SendMAp.push_back(Data);
     Send(SendMAp);
     

}