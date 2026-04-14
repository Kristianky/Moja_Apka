#include "ModbusParser.h"

Parser::Parser():MbapHead(0,2)
{
   
}

std::vector<uint8_t> Parser::BuildReadSingleCoil(const int Byte,const int Bit)
{
    std::vector<uint8_t> ReadRequest,PduHeadRead;
    MbapHead.Lenght = 6;
    PduHead.FunctionCode = 3;
    PduHead.Adress = static_cast<uint16_t>(Byte);
    PduHead.Quantity_Value = 0x0001;
    ReadRequest = MbapHead.BuildMap();
    PduHeadRead = PduHead.PDUMap();
    ReadRequest.insert(ReadRequest.end(),PduHeadRead.begin(),PduHeadRead.end());
    return ReadRequest;
}

std::vector<uint8_t> Parser::BuildWriteSingleCoil(const int Byte,const int Bit)
{
    std::vector<uint8_t> ReadRequest,PduHeadRead;
    MbapHead.Lenght = 6;
    PduHead.FunctionCode = 6;
    PduHead.Adress = static_cast<uint16_t>(Byte);
    PduHead.Quantity_Value = 0x0001;
    ReadRequest = MbapHead.BuildMap();
    PduHeadRead = PduHead.PDUMap();
    ReadRequest.insert(ReadRequest.end(),PduHeadRead.begin(),PduHeadRead.end());
    return ReadRequest;
}

ModbusFrame Parser::BuildFrame(const std::vector<uint8_t> &Data)
{
    HandleFrame.UnitID = Data.at(6);
    HandleFrame.FunctionCode = Data.at(7);
    HandleFrame.Adress =static_cast<uint16_t>(Data.at(8) >> 8)|static_cast<uint16_t>(Data.at(9));
    HandleFrame.QuantityValue = static_cast<uint16_t>(Data.at(10)>>8)|static_cast<uint16_t>(Data.at(11));
    // unsigned int SizeOfData = Data.size();
    // for(int i{12};i < Data.size();i++)
    // {
    //     HandleFrame.Data.push_back(Data.at(i));
    // }
    HandleFrame.Data.push_back(0x01);
    std::cout<<Data.size()<<"\n";
    int UnitIdINt = static_cast<int>(HandleFrame.UnitID);
    std::cout<<UnitIdINt<<"..."<<"..."<<HandleFrame.UnitID<<"\n";
    return HandleFrame;
}