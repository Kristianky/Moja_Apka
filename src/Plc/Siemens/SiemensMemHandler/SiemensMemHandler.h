#pragma once

#include "Converter.h"

class Date_And_Time
{
private:
    uint8_t Hour, Minute, Day, Mounth;
    uint16_t Year;

public:
void SetDateAndTime(std::vector<uint16_t> &Memory);
uint8_t GetHour() {return Hour;}
uint8_t GetMinute() {return Minute;}
uint8_t GetDay() {return Day;}
uint8_t GetMount() {return Mounth;}
uint16_t GetYear() {return Year;}

};

