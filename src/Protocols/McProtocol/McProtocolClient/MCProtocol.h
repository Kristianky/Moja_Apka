#ifndef _MCPROTOCOL_H_
#define _MCPROTOCOL_H_

#include "TcpClient.h"
#include "McProtocolParser.h"
#include "McHandler.h"
#include <functional>
#include <unordered_map>


class MCProtocol : public TCPClient
{
private:
        McProtocolParser McParser;

public:
        MCProtocol();
        ~MCProtocol() = default;
        std::unordered_map<std::string,std::function <void(std::vector<uint8_t>&,uint32_t&,uint16_t&)>> write;
        std::unordered_map<std::string,std::function <void(uint32_t&,uint16_t&)>> read;
        McProtocolParser GetMcParser() {return McParser;}
        void DisplayFrameToHandle(){std::cout<<McParser;}
};

#endif