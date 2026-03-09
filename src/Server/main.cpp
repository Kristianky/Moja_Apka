
#include <iostream>
#include <string>
#include "Converter.h"
#include "ModbusClient.h"

int main()
{
    ModbusClient Client;
    if (!Client.Connect("192.168.10.2",2505))
    {
        std::cout<<"Not Connected\n";
    }
    std::cout<<"What You wont to send: \n";
    std::string Buff;
    std::cin>>Buff;
    std::vector<uint8_t> BuffVec;
    BuffVec = StringToVector_Uint8(Buff);
    if(!Client.Send(BuffVec))
    {
        std::cout<<"Not Sended\n";
    }
    if(Client.Recieve() > 0)
    {
        std::cout<<Vector_Uint8_ToString(Client.GetRecvBuff())<<std::endl;
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