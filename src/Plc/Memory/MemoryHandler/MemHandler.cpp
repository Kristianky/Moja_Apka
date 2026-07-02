#include "MemHandler.hpp"

void Date_And_Time::SetDateAndTime(const std::vector<uint16_t> &Memory)
{
    Hour = Memory.at(20) & 0xFF;
    Minute = (Memory.at(20) >> 8) & 0xFF;
    Day = Memory.at(21) & 0xFF;
    Mounth = Memory.at(21) >> 8 & 0xFF;
    Year = Memory.at(22);
}

std::ostream &operator<<(std::ostream &os,Date_And_Time &RHS)
{
    os << RHS.Hour<<":"<<RHS.Minute<<":"<<" "<<RHS.Day<<"."<<RHS.Mounth<<"."<<RHS.Year<<"/n";
    return os;
}