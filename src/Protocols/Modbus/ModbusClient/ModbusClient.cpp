#include "ModbusClient.h"

ModbusClient::ModbusClient() : TCPClient()
{
}

std::vector<uint8_t> ModbusClient::ReadSingleCoil(const int Byte,const int Bit)
{
    std::vector<uint8_t> SendMap = ModbusParser.BuildReadSingleCoil(Byte,Bit),returnvalue;
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
    ModbusParser.BuildFrame(returnvalue);
    return returnvalue;
}

bool ModbusClient::WriteSingleCoil(const bool &Data, const int Byte, const int Bit)
{
    uint16_t value;
    std::vector<uint8_t> SendMAp;
    if (Bit > 15)
    {
        throw std::runtime_error("Bit out of range");
    }
    if (Data)
    {
        value |= (1 << Bit);
    }
    else
    {
        value &= ~(1 << Bit);
    }

    ModbusParser.SetQuantityValue(value);
    SendMAp = ModbusParser.BuildWriteSingleCoil(Byte,Bit);
    return Send(SendMAp);
}
