#include "ModbusClient.h"

ModbusClient::ModbusClient() : TCPClient(), ModbusHead(0, 2)
{
}

uint16_t ModbusClient::ReadSingleCoil()
{
    // Vytvorenie Hlavicky mbap pre modbus spojenie
    // transaction id su 2 byte ktorym sa identifikuje ukon
    return 0;
}

bool ModbusClient::WriteSingleCoil(const bool &Data, const int Byte, const int Bit)
{
    uint16_t value;
    if (Bit > 15)
    {
        throw std::runtime_error("Bit out of range");
    }
    ModbusHead.Lenght = 6;
    PDUHead.FunctionCode = 6;
    PDUHead.Adress = static_cast<uint16_t>(Byte);
    std::vector<uint8_t> SendMAp;
    if (Data)
    {
        value |= (1 << Bit);
    }
    else
    {
        value &= ~(1 << Bit);
    }

    PDUHead.Quantity_Value = value;
    std::vector<uint8_t> pdu = PDUHead.PDUMap();
    SendMAp = ModbusHead.BuildMap();
    SendMAp.insert(SendMAp.end(), pdu.begin(), pdu.end());
    return Send(SendMAp);
}