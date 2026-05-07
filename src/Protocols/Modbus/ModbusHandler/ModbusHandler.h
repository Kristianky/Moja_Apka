#pragma once

#include "ModbusFrame.h"
#include "Converter.h"

struct UnitInfo
{
    uint16_t TransactionID;
    std::string Unit;
};

struct DataInfo
{
    uint8_t FunctionCode;
    uint16_t Adress;
    uint16_t Quantity;
};

class ModbusHandler
{
private:
    ModbusFrame FrameToHandle;
    UnitInfo UnitInf;
    DataInfo DataInf;
    std::vector<bool> BooleanData;
    std::vector<int> IntData;
    std::vector<std::string> StringData;

private:
    void SetUnitInf(const ModbusFrame &Frame);
    void SetDataInf(const ModbusFrame &Frame);
    void SetData(const ModbusFrame &Frame);
    


    std::string GetPlcName() const { return UnitInf.Unit; }
    uint16_t GetTransactionID() const { return UnitInf.TransactionID; }
};