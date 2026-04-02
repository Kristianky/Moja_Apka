#include "Converter.h"

std::vector<uint8_t> StringToVector_Uint8(const std::string &ToConvert)
{
    std::vector<uint8_t> ReturnValue;
    if (ToConvert.length() == 0)
    {
        return ReturnValue;
    }
    for (long long unsigned int i{}; i < ToConvert.size(); i++)
    {
        ReturnValue.push_back((ToConvert.at(i)));
    }
    return ReturnValue;
}

std::string Vector_Uint8_ToString(const std::vector<uint8_t> &data)
{
    {
        if (data.empty())
            return "Data = 0";

        std::ostringstream oss;

        for (uint8_t byte : data)
        {
            oss << std::hex << std::setw(2) << std::setfill('0')
                << (int)byte << " ";
        }

        return oss.str();
    }
}

uint16_t DBX(int Byte, int Bit)
{
    if (Bit > 7)
    {
        if (Bit < 0 || Bit > 7)
        {
            throw std::runtime_error("Bit out of range");
        } // Bity mozu byt len do 7 ako u siemens
    }
    uint16_t offset = static_cast<uint16_t>(Byte * 8 + Bit);

    return offset;
}