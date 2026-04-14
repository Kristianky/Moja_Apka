
#include <iostream>
#include <string>
#include "ModbusClient.h"
#include "MCProtocol.h"

int main()
{
    int Choice{2};
    while (Choice > 1)
    {
        std::cout << "If you want modbus protocol press 0\n";
        std::cout << "If you want Mc Protcol press 1\n";
        std::cin >> Choice;
    }
    if (Choice == 0)
    {
        ModbusClient Client;
        if (!Client.Connect("192.168.10.2", 2505))
        {
            std::cout << "Not Connected\n";
        }
        std::cout << "What You wont to send: \n";
        std::string Buff;
        std::cin >> Buff;
        std::vector<uint8_t> BuffVec;
        BuffVec = StringToVector_Uint8(Buff);
        if (!Client.WriteSingleCoil(true, 0, 0))
        {
            std::cout << "Not Sended\n";
        }
        std::cout<<Vector_Uint8_ToString(Client.ReadSingleCoil(0,0))<<"\n";
        std::cout << "For End Press any number\n";
        int end;
        std::cin >> end;
        Client.Disconnect();
        return 1;
    }
    else if (Choice == 1)
    {
        MCProtocol mntnc;
        mntnc.Connect("192.168.10.2", 2505);
        mntnc.WriteMBit(false, 0x00);
        mntnc.ReadMBit(0x00);
        std::cout << Vector_Uint8_ToString(mntnc.GetRecvBuff()) << std::endl;
        std::cout << "\nFor End Press any number\n";
        int end;
        std::cin >> end;
        mntnc.Disconnect();

        return 2;
    }

    return 0;
}