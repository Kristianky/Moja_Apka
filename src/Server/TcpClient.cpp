#include "TcpClient.h"

bool TCPClient::Connect()
{

    WSADATA wsaData;
    int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (Result != 0)
    {
        return false;
    }
    m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in Server;
    Server.sin_family = AF_INET;
    Server.sin_port = htons(2505);
    Server.sin_addr.s_addr = inet_addr("192.168.10.2");

    int Connect_Result = connect(m_Socket, (SOCKADDR *)&Server, sizeof(Server));
    if (Connect_Result == SOCKET_ERROR)
    {
        closesocket(m_Socket);
        WSACleanup();
        m_Socket = INVALID_SOCKET;
        return false;
    }

    return true;
}

void TCPClient::Disconnect()
{
    closesocket(m_Socket);
    WSACleanup();
    m_Socket = INVALID_SOCKET;
}

bool TCPClient::Send(std::string &Buffer)
{
    int Error_Send = send(m_Socket,Buffer.c_str(),13,0);
    if(Error_Send == SOCKET_ERROR)
    {
       return false;
    }
    return true;
}

bool TCPClient::Recieve()
{
    return false;
}