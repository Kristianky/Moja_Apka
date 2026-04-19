#ifndef _MCPROTOCOL_H_
#define _MCPROTOCOL_H_

#include "TcpClient.h"
#include "McProtocolParser.h"


class MCProtocol : public TCPClient
{
private:
        Header HeadReq;

public:
        MCProtocol();
        ~MCProtocol() = default;
        void WriteMBit(const bool &Data, const uint16_t &Adrres);
        void ReadMBit(const uint16_t &Adrres);
};

#endif