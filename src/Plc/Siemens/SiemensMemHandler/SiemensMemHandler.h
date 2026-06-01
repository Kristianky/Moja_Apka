#pragma once

#include "Converter.h"

class Date_And_Time
{
private:
    uint8_t Hour, Minute, Day, Mounth;
    uint16_t Year;

public:
void SetDateAndTime(std::vector<uint16_t> &Memory);

};

