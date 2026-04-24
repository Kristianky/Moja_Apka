#pragma once
#include "Converter.h"
#include <vector>

class ModbusFrame;
std::ostream &operator<<(std::ostream &Os,const ModbusFrame &Rhs);

class ModbusFrame
{
    private:
       uint16_t TransactionID;
       uint8_t UnitID;
       uint8_t FunctionCode;
       uint16_t Adress;
       uint16_t QuantityValue;
       std::vector<uint8_t> Data;
    public:
       void SetTransactionID(const std::vector<uint8_t> &InputFrame);
       void SetUnitID(const std::vector<uint8_t> &InputFrame);
       void SetFunctionCode(const std::vector<uint8_t> &InputFrame);
       void SetAdress(const std::vector<uint8_t> &InputFrame);
       void SetQuantityValue(const std::vector<uint8_t> &InputFrame);
       void SetData (const std::vector<uint8_t> &InputFrame);
       friend std::ostream &operator<<(std::ostream &Os,const ModbusFrame &Rhs);
};