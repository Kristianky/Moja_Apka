#include "TCPClient.h"
#include <iostream>
#include <string>

int main()
{
    TCPClient Client;
    if (!Client.Connect())
    {
        std::cout<<"Not Connected\n";
    }
    std::cout<<"What You wont to send: \n";
    std::string Buff;
    std::cin>>Buff;
    if(!Client.Send(Buff))
    {
        std::cout<<"Not Sended\n";
    }
    if(Client.Recieve() > 0)
    {
        std::cout<<Client.GetRecvBuff()<<std::endl;
    }
    else
    {
        std::cout<<"Server sa zatvoril";
    }
    std::cout<<"For End Press any number\n";
    int end;
    std::cin>>end;
    Client.Disconnect();
    return 0;
}