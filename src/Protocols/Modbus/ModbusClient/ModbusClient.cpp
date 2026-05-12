#include "ModbusClient.h"

ModbusClient::ModbusClient() : TCPClient()
{
}

std::vector<uint8_t> ModbusClient::ReadCoils(const int Byte, const int Lenght)
{
    std::vector<uint8_t> SendMap = ModbusPArser.BuildMaps[1](Byte, Lenght), returnvalue;
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
        throw std::runtime_error("Send Fail");
    }
    // ModbusPArser.BuildFrame(returnvalue);
    ModbusHNDlr.BuildCiols(returnvalue, Lenght);
    return returnvalue;
}

bool ModbusClient::WriteSingleCoil(const bool &Data, const int Byte, const int Bit)
{
    uint16_t value;
    std::vector<uint8_t> SendMAp, RcvMap;

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

    ModbusPArser.SetQuantityValue(value);
    SendMAp = ModbusPArser.BuildWriteSingleCoil(Byte, Bit);
    return Send(SendMAp);
}
