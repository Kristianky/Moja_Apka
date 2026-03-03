#include "Converter.h"

std::vector<uint8_t> StringToVector_Uint8(const std::string &ToConvert)
{
    std::vector<uint8_t> ReturnValue;
    if(ToConvert.length() == 0)
    {
        return ReturnValue;
    }
    for(long long unsigned int i{};i < ToConvert.size();i++)
    {
        ReturnValue.push_back((ToConvert.at(i)));
    }
    return ReturnValue;

}

std::string Vector_Uint8_ToString(const std::vector<uint8_t> &ToCnvert)
{
    std::string ReturnValue;
    if(ToCnvert.size() == 0)
    {
        ReturnValue = "Data = 0";
        return ReturnValue;
    }
    for(long long unsigned int i{};i < ToCnvert.size();i++)
    {
        ReturnValue.push_back(ToCnvert.at(i));
    }
    return ReturnValue;

}