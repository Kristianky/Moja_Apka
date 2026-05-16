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

bool ModbusClient::WriteCoils(const std::vector<bool>& Data,
                              const uint16_t Byte,
                              const uint16_t Lenght)
{
    uint16_t Count = 0;

    std::vector<uint8_t> SendMap, DataToSend;

    uint16_t ByteLenght = (Lenght + 15) / 16;

    for(uint16_t i = 0; i < ByteLenght; i++)
    {
        uint8_t Mask = 0;

        for(uint16_t j = 0; j < 16 && Count < Lenght; j++)
        {
            if(Data.at(Count))
            {
                Mask |= (1 << j);
            }

            Count++;
        }

        DataToSend.push_back(Mask);
    }

    SendMap = ModbusPArser.BuildMaps[15](Byte, Lenght);

    SendMap.push_back(ByteLenght);

    SendMap.insert(SendMap.end(),
                   DataToSend.begin(),
                   DataToSend.end());

    return Send(SendMap);
}

bool ModbusClient::WriteRegisters(std::vector<uint8_t> &Data, const uint16_t Byte, const uint16_t Lenght)
{
    uint16_t value;
    std::vector<uint8_t> SendMAp, RcvMap;

    ModbusPArser.SetQuantityValue(value);
    SendMAp = ModbusPArser.BuildMaps[15](Byte, Lenght);
    return Send(SendMAp);
}
