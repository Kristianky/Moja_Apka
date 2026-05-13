#include "MCProtocol.h"

MCProtocol::MCProtocol() : TCPClient()
{
    write["M"] = [this](std::vector<uint8_t> &Data, uint32_t &Adress,uint16_t &Lenght)
    {
        std::vector<uint8_t> ToSend = McParser.WriteBitHead("M", Adress, 1);
        uint8_t DataSend = Data.at(0);
        ToSend.push_back(DataSend);
        Send(ToSend);
        int Result = Recieve();
    };
    write["D"] = [this](std::vector<uint8_t> &Data, uint32_t &Adress,uint16_t &Lenght)
    {

    };
    read["M"] = [this](uint32_t &Adress,uint16_t &Lenght)
    {
        std::vector<uint8_t> ToSend = McParser.ReadBitHead("M", Adress, Lenght);
        Send(ToSend);
        Recieve();
        McParser.CreateFrameToHandler(GetRecvBuff());
    };
}
