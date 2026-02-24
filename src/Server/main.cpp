#include "TCPClient.h"
#include <iostream>

int main()
{
    TCPClient Client;
    if (!Client.Connect())
    {
        std::cout<<"Not Connected";
    }
    if(!Client.Send())
    {
        std::cout<<"Not Sended";
    }
    Client.Disconnect();
    return 0;
}