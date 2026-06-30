#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include <winsock2.h>
#include <string>
#include <vector>
#include <cstdint>

class TCPClient
{
private:
    SOCKET m_Socket;
    std::vector<uint8_t> RecvBuff;
    bool Conected;
public:
    TCPClient():m_Socket{INVALID_SOCKET}{}
    ~TCPClient(){Disconnect();}
    void Disconnect();
    bool Connect(const char *IpAdrres,const int Port);
    bool Send(std::vector<uint8_t> &Buffer);
    int Recieve();
    std::vector<uint8_t> GetRecvBuff() {return RecvBuff;}
    bool Get_Connected(){return Conected;}
};

#endif