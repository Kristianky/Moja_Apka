#include "ModbusHandler.h"

void ModbusHandler::SetUnitInf(const ModbusFrame &Frame)
{
    UnitInf.TransactionID = Frame.GetTransactionID();
    if(Frame.GetUnitID() == 2)
    {
        UnitInf.Unit = "SiemensPlc Virtual 1";
    }
}

void ModbusHandler::SetDataInf(const ModbusFrame &Frame)
{
    DataInf.FunctionCode = Frame.GetFunctionCode();
    DataInf.Adress = Frame.GetAdress();
    DataInf.Quantity = Frame.GetQuantity();
}

void ModbusHandler::SetData(const ModbusFrame &Frame)
{
    
}