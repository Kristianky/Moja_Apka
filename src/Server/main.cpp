#include "TCPClient.h"
#include <iostream>
#include <string>

int main()
{
    TCPClient Client;
    if (!Client.Connect())
    {
        std::cout<<"Not Connected";
    }
    std::cout<<"What You wont to send: \n";
    std::string Buff;
    std::cin>>Buff;
    if(!Client.Send(Buff))
    {
        std::cout<<"Not Sended";
    }
    std::cout<<"For End Press any number";
    int end;
    std::cin>>end;
    Client.Disconnect();
    return 0;
}