#include "MCProtocol.h"

MCProtocol::MCProtocol() : TCPClient()
{
    HeadReq.SubHeader = 0x0050;
    HeadReq.Network_No = 0x00;
    HeadReq.PLC_No = 0xFF;
    HeadReq.IO_No = 0x03FF;
    HeadReq.Station_No = 0x00;
    HeadReq.Monitoring_Timer = 0x000a;
}

void MCProtocol::WriteMBit(const bool &Value, const uint16_t &Adress)
{
    HeadReq.Comand = 0x1401;
    HeadReq.SubComand = 0x0001;
    HeadReq.DeviceCode = 0x90;
    HeadReq.Adress1 = 0x00C8;
    HeadReq.Adress2 = 0x00;
    HeadReq.DevicePoints = 0x0001;
    HeadReq.Request_Data_Lenght = 0x000D;
    std::vector<uint8_t> ToSend = HeadReq.Map();
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

void MCProtocol::ReadMBit(const uint16_t &Adress)
{
    HeadReq.Comand = 0x0401;
    HeadReq.SubComand = 0x0001;
    HeadReq.DeviceCode = 0x90;
    HeadReq.Adress1 = 0x00c8;
    HeadReq.Adress2 = 0x00;
    HeadReq.DevicePoints = 0x0001;
    HeadReq.Request_Data_Lenght = 0x000C;
    std::vector<uint8_t> ToSend = HeadReq.Map();
    Send(ToSend);
    Recieve();
}