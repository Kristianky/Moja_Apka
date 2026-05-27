#include "SiemensModbusMem.h"

void ModbusMemory::MemsInit(const std::vector<uint16_t> &Data)
{
    Registers.clear();
   
    Registers.assign(Data.begin(),Data.end());


} 

void ModbusMemory::MemsAtInit(const uint16_t &Data,const uint16_t &Adress)
{
    if(Adress < Registers.size())
    Registers.at(Adress) = Data;
}

uint16_t ModbusMemory::GetMem1(const uint16_t &Adress)
{
    if(Adress < Registers.size())
    return Registers.at(Adress);
    else
    return -1;
}

std::vector<uint16_t> ModbusMemory::GetMems(const uint16_t &StartAdress,const uint16_t &Lenght)
{
    std::vector<uint16_t> ReturnValue;
    uint16_t Size = StartAdress + Lenght;
    if(Size < Registers.size())
    ReturnValue.assign(Registers.begin() + StartAdress,Registers.begin() + Size);
    else 
    return ReturnValue;
}

