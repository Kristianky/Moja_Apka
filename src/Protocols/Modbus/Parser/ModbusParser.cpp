#include "ModbusParser.h"

ModbusParser::ModbusParser():MbapHead(0,2)
{
   
}

std::vector<uint8_t> ModbusParser::BuildReadSingleCoil(const int Byte,const int Bit)
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

std::vector<uint8_t> ModbusParser::BuildWriteSingleCoil(const int Byte,const int Bit)
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

void ModbusParser::BuildFrame(const std::vector<uint8_t> &Data)
{
    HandleFrame.SetTransactionID(Data);
    HandleFrame.SetUnitID(Data);
    HandleFrame.SetFunctionCode(Data);
    HandleFrame.SetAdress(Data);
    HandleFrame.SetQuantityValue(Data);
}

std::ostream &operator<<(std::ostream &Os,const ModbusParser &Rhs)
{
    Os<<Rhs.HandleFrame;
    return Os;
}