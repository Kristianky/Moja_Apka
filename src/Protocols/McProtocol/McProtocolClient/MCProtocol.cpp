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
        std::vector<uint8_t> ToSend = McParser.ReadBitHead(Register, Adress, Lenght),Buff;
        Send(ToSend);
        int Result = Recieve();
        McParser.CreateFrameToHandler(GetRecvBuff());
        if(Result == 0)
        Buff = GetRecvBuff();
        return Buff;
    };
    read["W"] = read["B"] = [this](uint32_t &Adress, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.ReadWordHead(Register, Adress, Lenght),Buff;
        Send(ToSend);
        int Result = Recieve();
        McParser.CreateFrameToHandler(GetRecvBuff());
        if(Result == 0)
        Buff = GetRecvBuff();
        return Buff;
    };
    WriteBW["BW"] = [this](std::vector<uint8_t> Data,uint32_t &Adress,uint16_t &Bit, uint16_t &Lenght,std::string Register)
    {
        std::vector<uint16_t> Registers;
        uint16_t LenghtBool = ((Lenght + 15) / 16) + 1;
        std::vector<uint8_t> ToSend = McParser.WriteWordHead(Register,Adress,LenghtBool);
        for(uint16_t i{0};i < Data.size();i++)
        {
            

        }



        return;
    };
}

void MCProtocol::MemoryInit(std::vector<uint16_t> &Data)
{
    if(TCPClient::Get_Connected())
    {
        uint32_t Adrres = 6000;
        uint16_t Lenght = 3000;
        MCProtocol::read["B"](Adrres,Lenght,"M");
        MCProtocol::read["W"](Adrres,Lenght,"D");
    }
}
