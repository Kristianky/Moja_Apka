#ifndef _MCPROTOCOL_H_
#define _MCPROTOCOL_H_

#include "TcpClient.h"
#include "McProtocolParser.h"
#include "McHandler.h"
class MCProtocol : public TCPClient
{
private:
        McProtocolParser McParser;

public:
        MCProtocol();
        ~MCProtocol() = default;
        void WriteMBit(const bool &Data, const uint32_t &Adrres);
        void ReadMBit(const int32_t &Adrres);
        McProtocolParser GetMcParser() {return McParser;}
        void DisplayFrameToHandle(){std::cout<<McParser;}
};

#endif