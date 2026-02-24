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
    Server.sin_port = 502;
    Server.sin_addr.s_addr = inet_addr("129.168.0.1");

    int Connect_Result = connect(m_Socket, (SOCKADDR *)&Server, sizeof(Server));
    if (Connect_Result == INVALID_SOCKET)
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

bool TCPClient::Send()
{
    int Error_Send = send(m_Socket,"Ahoooj",7,0);
    if(Error_Send == SOCKET_ERROR)
    {
       return false;
    }
    return true;
}

bool TCPClient::Recieve()
{
    
}