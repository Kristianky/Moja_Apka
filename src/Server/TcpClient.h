#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include <winsock2.h>
#include <string>

class TCPClient
{
private:
    SOCKET m_Socket;
    std::string RecvBuff;
public:
    TCPClient():m_Socket{INVALID_SOCKET}{}
    ~TCPClient(){Disconnect();}
    void Disconnect();
    bool Connect();
    bool Send(std::string &Buffer);
    int Recieve();
    std::string GetRecvBuff() {return RecvBuff;}
};

#endif