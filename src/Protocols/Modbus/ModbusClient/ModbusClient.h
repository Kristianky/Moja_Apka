#ifndef _MODBUSCLIENT_H_
#define _MODBUSCLIENT_H_

#include "TcpClient.h"
#include <vector>
#include "Converter.h"
#include <string>
#include "ModbusParser.h"
#include "ModbusHandler.h"


class ModbusClient : public TCPClient
{
private:
    ModbusParser ModbusPArser;
    ModbusHandler ModbusHNDlr;
public:
    ModbusClient();
    ~ModbusClient() = default;
    std::vector<uint8_t> ReadCoils(int Byte,int Lenght);
    bool WriteSingleCoil(const bool &Data,const int Byte,const int Bit);
    uint16_t ReadInputRegister();
    void DisplayFrame(){std::cout<<ModbusPArser.GetHandleFrame();}
    void DisplayBoolData(int Index){std::cout<<ModbusHNDlr.GetBoolData(Index)<<std::endl;}
};

#endif