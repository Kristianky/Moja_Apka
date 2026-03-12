#include "ModbusClient.h"

ModbusClient::ModbusClient() : TCPClient(), ModbusHead(0, 2)
{
}

uint8_t ModbusClient::ReadSingleCoil()
{
    // Vytvorenie Hlavicky mbap pre modbus spojenie
    // transaction id su 2 byte ktorym sa identifikuje ukon
    return 0;
}

bool ModbusClient::WriteSingleCoil(const bool &Data, const int Byte, const int Bit)
{
    ModbusHead.Lenght = 6;
    PDUHead.FunctionCode = 6;
    PDUHead.Adress = DBX(Byte,Bit);
    std::vector<uint8_t> SendMAp;
    if(Data)
    {
        PDUHead.Quantity_Value = 0x2200;
    }
    else
    {
        PDUHead.Quantity_Value = 0x0000;
    }
    std::vector<uint8_t> pdu = PDUHead.PDUMap();
    SendMAp = ModbusHead.BuildMap();
    SendMAp.insert(SendMAp.end(), pdu.begin(), pdu.end());
    return Send(SendMAp);
}