#include "MemHandler.h"

void Date_And_Time::SetDateAndTime(std::vector<uint16_t> &Memory)
{
    Hour = Memory.at(0) & 0xFF;
    Minute = (Memory.at(0) >> 8) & 0xFF;
    Day = Memory.at(1) & 0xFF;
    Mounth = Memory.at(1) >> 8 & 0xFF;
    Year = Memory.at(2);
}