#ifndef _MCPROTOCOL_H_
#define _MCPROTOCOL_H_

#include "TcpClient.h"

struct Header
{
        // mcProtocol header
        uint16_t SubHeader;
        uint8_t Network_No;
        uint8_t PLC_No;
        uint16_t IO_No;
        uint8_t Station_No;
        uint16_t Request_Data_Lenght;
        uint16_t Monitoring_Timer;
        // Mcprotocl comands
        uint16_t Comand;
        uint16_t SubComand;
        uint16_t EndCode;
        uint16_t ErrorInfo;
        std::vector<uint8_t> Map()
        {
                std::vector<uint8_t> map;
                map.push_back(SubHeader >> 8);
                map.push_back(SubHeader & 0xFF);

                map.push_back(Network_No);

                map.push_back(PLC_No);

                map.push_back(IO_No >> 8);
                map.push_back(IO_No & 0xFF);

                map.push_back(Station_No);

                map.push_back(Request_Data_Lenght >> 8);
                map.push_back(Request_Data_Lenght & 0xFF);

                map.push_back(Monitoring_Timer >> 8);
                map.push_back(Monitoring_Timer & 0xFF);

                map.push_back(Comand >> 8);
                map.push_back(Comand & 0xFF);

                map.push_back(SubComand >> 8);
                map.push_back(SubComand & 0xFF);

                map.push_back(EndCode >> 8);
                map.push_back(EndCode & 0xFF);

                map.push_back(ErrorInfo >> 8);
                map.push_back(ErrorInfo & 0xFF);
                return map;
        }
};

class MCProtocol : public TCPClient
{
        private:
        Header HeadReq;
public:
        MCProtocol();
        ~MCProtocol() = default;
        void SetHeader();
};

#endif