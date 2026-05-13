#include "MCProtocol.h"

MCProtocol::MCProtocol() : TCPClient()
{
    write["B"] = [this](std::vector<uint8_t> &Data, uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.WriteBitHead(Register, Adress, Lenght);
        uint8_t DataSend = Data.at(0);
        ToSend.push_back(DataSend);
        Send(ToSend);
        int Result = Recieve();
    };
    write["W"] = [this](std::vector<uint8_t> &Data, uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.WriteWordHead(Register, Adress, Lenght);
        uint8_t DataSend = Data.at(0);
        ToSend.push_back(DataSend);
        Send(ToSend);
        int Result = Recieve();
    };
    read["B"] = [this](uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.ReadBitHead(Register, Adress, Lenght);
        Send(ToSend);
        Recieve();
        McParser.CreateFrameToHandler(GetRecvBuff());
    };
    read["W"] = read["B"] = [this](uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.ReadWordHead(Register, Adress, Lenght);
        Send(ToSend);
        Recieve();
        McParser.CreateFrameToHandler(GetRecvBuff());
    };
}
