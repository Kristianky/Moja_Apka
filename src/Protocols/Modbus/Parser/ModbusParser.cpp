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