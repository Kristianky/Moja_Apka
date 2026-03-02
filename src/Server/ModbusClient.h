#ifndef _MODBUSCLIENT_H_
#define _MODBUSCLIENT_H_

#include "TcpClient.h"
#include <vector>
// Classa pre mbap co je 7 byte hlavicka na idetentifikovanie v modbus komunikacii
class MBAP
{
private:
public:
    uint16_t TransactionID; // Je to identifikacia cisla transakcie
    uint16_t ProtocolIdent; // Je to aby sme vedeli aky protokol bol pouzity pre modbus je to 0
    uint16_t Lenght;        // Tu zadavame Unit ID a PDU velkost pre PDU hlavicku
    uint8_t unitID;         // Je to nieco ako profbus adrres daneho zariadenia
    MBAP(uint16_t lenght, uint16_t unitid) : Lenght{lenght}, unitID{unitid}
    {
        TransactionID = 0;
        ProtocolIdent = 0;
    }
    std::vector<uint8_t> BuildMap()
    {
        std::vector<uint8_t> mbap;
        mbap.push_back(TransactionID >> 8);
        mbap.push_back(TransactionID & 0xFF);

        mbap.push_back(ProtocolIdent >> 8);
        mbap.push_back(ProtocolIdent & 0xFF);

        mbap.push_back(Lenght >> 8);
        mbap.push_back(Lenght & 0xFF);

        mbap.push_back(unitID);
    }
};

class PDU
{
private:
public:
    uint8_t FunctionCode; // tu urcujeme aku chcem funckiu napr 01 read coils
    uint16_t Adress;      // tu urcujeme adresu uz napr z db v siemens
    uint16_t Quantity;    // tu urcujeme quantitu kolko registrov alebo coils chceme precitat
    PDU(uint16_t functioncode = 1, uint16_t adress = 0, uint16_t quantity = 1)
        : FunctionCode{functioncode}, Adress{adress}, Quantity{quantity}
    {
    }
    std::vector<uint8_t> PDUMap()
    {
        std::vector<uint8_t> Map;
        Map.push_back(FunctionCode);
        
        Map.push_back(Adress >> 8);
        Map.push_back(Adress & 0xFF);

        Map.push_back(Quantity >> 8);
        Map.push_back(Quantity & 0xFF);
    }
};

class ModbusClient : public TCPClient
{
public:
    ModbusClient();
    ~ModbusClient() = default;
    uint8_t ReadSingleCoil();
};

#endif