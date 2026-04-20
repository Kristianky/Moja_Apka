#pragma once

#include "Converter.h"
#include <vector>

class McProtocolFrame
{
private:
    uint16_t Comand;
    uint16_t SubComand;
    uint8_t DeviceCode;
    uint16_t Adress1;
    uint8_t Adress2;
    uint16_t DevicePoints;
};