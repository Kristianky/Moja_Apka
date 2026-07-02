
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
        while (Choice != -1)
        {
            std::vector<bool> DAtaSend = {true, true, false, true};
            ModbusClient Client;
            if (!Client.Connect("192.168.10.2", 2505))
            {
                std::cout << "Not Connected\n";
            }
            else
            {
                Client.InitMemory();

                if (!Client.WriteCoils(DAtaSend, 0, 4))
                {
                    std::cout << "Not Sended\n";
                }
                if (Client.Recieve())
                {
                }
                int Byte, Lenght;
                std::cout << "Write Adress and Lenght: \n";
                std::cin >> Byte;
                std::cin >> Lenght;
                std::cout << Vector_Uint8_ToString(Client.ReadCoils(Byte, Lenght)) << "\n";
                Client.DisplayCoils();
                std::cout << "For End Press any number\n";
                std::cin >> Choice;
                Client.Disconnect();
                {
                    return 1;
                }
            }
        }
    }
    else if (Choice == 1)
    {
        MCProtocol mntnc;
        mntnc.Connect("192.168.1.2", 2505);
        while (Choice != -1)
        {
            std::vector<uint16_t> Data;
            bool value;
            std::uint32_t Adress;
            std::cout << "Write value 0 or 1";
            std::cin >> value;
            std::cout << "Write adress";
            std::cin >> Adress;
            if (value)
            {
                Data.push_back(0x10);
            }
            else
            {
                Data.push_back(0x00);
            }
            uint16_t Lenght = 1;
            mntnc.write["W"](Uint16_To_Uint8_Litle(Data), Adress, Lenght, "D");
            mntnc.read["W"](Adress, Lenght, "D");
            std::cout << Vector_Uint8_ToString(mntnc.GetRecvBuff()) << std::endl;
            mntnc.DisplayFrameToHandle();

            std::cout << "For end type -1.";
            std::cin >> Choice;
        }
        mntnc.Disconnect();
    }

    return 0;
}