#include "MCProtocol.h"

MCProtocol::MCProtocol() : TCPClient()
{
    write["B"] = [this](std::vector<uint8_t> Data, uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.WriteBitHead(Register, Adress, Lenght);
        ToSend.insert(ToSend.end(),Data.begin(),Data.end());
        Send(ToSend);
        int Result = Recieve();
        if(Result == 0)
        return;
    };
    write["W"] = [this](std::vector<uint8_t> Data, uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.WriteWordHead(Register, Adress, Lenght);
        
        Send(ToSend);
        int Result = Recieve();
        if(Result == 0)
        return;
    };
    read["B"] = [this](uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.ReadBitHead(Register, Adress, Lenght);
        Send(ToSend);
        int Result = Recieve();
        McParser.CreateFrameToHandler(GetRecvBuff());
        if(Result == 0)
        return;
    };
    read["W"] = read["B"] = [this](uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.ReadWordHead(Register, Adress, Lenght);
        Send(ToSend);
        int Result = Recieve();
        McParser.CreateFrameToHandler(GetRecvBuff());
        if(Result == 0)
        return;
    };
    write["BW"] = [this](std::vector<uint8_t> Data,uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.WriteWordHead(Register,Adress,Lenght);
        uint16_t LenghtBool = ((Lenght + 15) / 16) + 1;


        return;
    };
}
