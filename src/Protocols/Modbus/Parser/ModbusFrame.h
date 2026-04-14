#pragma once
#include "Converter.h"
#include <vector>

class ModbusFrame
{
    public:
       uint8_t UnitID;
       uint8_t FunctionCode;
       uint16_t Adress;
       uint16_t QuantityValue;
       std::vector<uint8_t> Data;
};