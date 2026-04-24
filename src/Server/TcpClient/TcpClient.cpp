#include "TcpClient.h"

bool TCPClient::Connect(const char *IpAdrres, const int Port)
{

    WSADATA wsaData;
    int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (Result != 0)
    {
        return false;
    }
    m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    int DotCount{}, Index{1};
    while (IpAdrres[Index - 1] != '\0')
    {
        if (IpAdrres[Index] == '.')
        {
            DotCount++;
        }
        Index++;
    }

    if (DotCount == 3) // Znamena ze nie je spravny tvar ip
    {
        sockaddr_in Server;
        Server.sin_family = AF_INET;
        Server.sin_port = htons(Port);
        Server.sin_addr.s_addr = inet_addr(IpAdrres);

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
    else
    {
        return false;
    }
}
void TCPClient::Disconnect()
{
    closesocket(m_Socket);
    WSACleanup();
    m_Socket = INVALID_SOCKET;
}

bool TCPClient::Send(std::vector<uint8_t> &Buffer)
{
    int Error_Send = send(m_Socket, reinterpret_cast<char *>(Buffer.data()), Buffer.size(), 0);
    if (Error_Send == SOCKET_ERROR)
    {
        return false;
    }
    return true;
}

int TCPClient::Recieve()
{
    {
        char RecvBuffTemp[256]; // väčší buffer
        int Length = recv(m_Socket, RecvBuffTemp, sizeof(RecvBuffTemp), 0);

        if (Length > 0)
        {
            RecvBuff.clear();
            for (int i = 0; i < Length; i++)
            {
                RecvBuff.push_back(RecvBuffTemp[i]);
            }
        }

        return Length;
    }
}