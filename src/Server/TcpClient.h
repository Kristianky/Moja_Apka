#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include <winsock2.h>

class TCPClient
{
private:
    SOCKET m_Socket;
public:
    TCPClient():m_Socket{INVALID_SOCKET}{}
    ~TCPClient(){Disconnect();}
    void Disconnect();
    bool Connect();
    bool Send();
    bool Recieve();
};

#endif