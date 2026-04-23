#include "MCProtocol.h"

MCProtocol::MCProtocol() : TCPClient()
{
}

void MCProtocol::WriteMBit(const bool &Value, const uint32_t &Adress)
{
    std::vector<uint8_t> ToSend = McParser.WriteBitHead("M",Adress,1);
    uint8_t Data;
    if(Value)
    {
        Data = 0x10;
    }
    else
    {
        Data = 0x00;
    }
    ToSend.push_back(Data);
    Send(ToSend);

    

}

void MCProtocol::ReadMBit(const int32_t &Adress)
{
    std::vector<uint8_t> ToSend = McParser.ReadBitHead("M",Adress,1);
    Send(ToSend);
    Recieve();
    McParser.CreateFrameToHandler(GetRecvBuff());
}