#include "McProtocolParser.h"

McProtocolParser::McProtocolParser()
{
    HeadReq.SubHeader = 0x0050;
    HeadReq.Network_No = 0x00;
    HeadReq.PLC_No = 0xFF;
    HeadReq.IO_No = 0x03FF;
    HeadReq.Station_No = 0x00;
    HeadReq.Monitoring_Timer = 0x000a;
}

std::vector<uint8_t> McProtocolParser::ReadBitHead(const std::string &MemoryArea, const int32_t &Adress, const int &Points)
{
    std::vector<uint8_t> ReturnValue;
    HeadReq.Comand = 0x0401;
    HeadReq.SubComand = 0x0001;
    HeadReq.DeviceCode = StringToMcProtocolMemoryArea(MemoryArea);
    uint32_t AdressTemp = IntToMcProtocolAdress(Adress);
    HeadReq.Adress1 = (AdressTemp >> 16) & 0xFFFF ;
    HeadReq.Adress2 = (AdressTemp >> 8) & 0xFF;
    HeadReq.DevicePoints = 0x0001;
    HeadReq.Request_Data_Lenght = 0x000C;
    ReturnValue = HeadReq.Map();
    return ReturnValue;
}

std::vector<uint8_t> McProtocolParser::WriteBitHead(const std::string &MemoryArea,const int32_t &Adress,const int &Points)
{
    std::vector<uint8_t> ReturnValue;
    HeadReq.Comand = 0x1401;
    HeadReq.SubComand = 0x0001;
    HeadReq.DeviceCode = StringToMcProtocolMemoryArea(MemoryArea);
    uint32_t AdressTemp = IntToMcProtocolAdress(Adress);
    HeadReq.Adress1 = (AdressTemp >> 16) & 0xFFFF ;
    HeadReq.Adress2 = (AdressTemp >> 8) & 0xFF;
    HeadReq.DevicePoints = 0x0001;
    HeadReq.Request_Data_Lenght = 0x000D;
    ReturnValue = HeadReq.Map();
    return ReturnValue;
}

void McProtocolParser::CreateFrameToHandler(const std::vector<uint8_t> &InputFrame)
{
    PlcFrame.SetSubHeader(InputFrame);
    PlcFrame.SetEndCode(InputFrame);
    PlcFrame.SetData(InputFrame);
}

std::ostream &operator<<(std::ostream &Os,const McProtocolParser &Rhs)
{
    Os<<Rhs.PlcFrame;
    return Os;
}