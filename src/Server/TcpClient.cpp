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

bool TCPClient::Send(std::vector<uint8_t> &Buffer)
{
    int Error_Send = send(m_Socket, reinterpret_cast<char*>(Buffer.data()), Buffer.size(), 0);
    if (Error_Send == SOCKET_ERROR)
    {
        return false;
    }
    return true;
}

int TCPClient::Recieve()
{
    uint8_t *RecvBuffTemp = new uint8_t[20];
    int Lenght = recv(m_Socket, reinterpret_cast<char*>(RecvBuffTemp), 20, 0);
    if (Lenght > 0)
    {
        RecvBuff = RecvBuffTemp;
        return Lenght;
    }
    return Lenght;
}