#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include <string>
#include <vector>
#include <cstdint>


    std::vector<uint8_t> StringToVector_Uint8(const std::string &ToCnovert);
    std::string Vector_Uint8_ToString(const std::vector<uint8_t> &ToConvert);

#endif