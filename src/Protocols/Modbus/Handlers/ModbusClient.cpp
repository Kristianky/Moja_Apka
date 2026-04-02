#include "ModbusClient.h"

ModbusClient::ModbusClient() : TCPClient(), ModbusHead(0, 2)
{
}

std::vector<uint8_t> ModbusClient::ReadSingleCoil()
{
    std::vector<uint8_t> returnvalue;
    ModbusHead.Lenght = 6;
    PDUHead.FunctionCode = 3;
    PDUHead.Adress = 0;
    PDUHead.Quantity_Value = 0x0001;
    std::vector<uint8_t> SendMap, pdu;
    SendMap = ModbusHead.BuildMap();
    pdu = PDUHead.PDUMap();
    SendMap.insert(SendMap.end(), pdu.begin(), pdu.end());
    if (Send(SendMap))
    {
        int Lenght = Recieve();
        if (Lenght > 0)
            returnvalue = GetRecvBuff();
        else
        {
            throw std::runtime_error("Recv = 0");
        }
    }
    else
    {
        throw std::runtime_error("Bit out of range");
    }

    return returnvalue;
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