#ifndef _MODBUSCLIENT_H_
#define _MODBUSCLIENT_H_

#include "TcpClient.h"
#include <vector>
#include "Converter.h"
#include <string>
#include "ModbusParser.h"


class ModbusClient : public TCPClient
{
private:
    Parser ModbusParser;
public:
    ModbusClient();
    ~ModbusClient() = default;
    std::vector<uint8_t> ReadSingleCoil(int Byte,int Bit);
    bool WriteSingleCoil(const bool &Data,const int Byte,const int Bit);
};

#endif