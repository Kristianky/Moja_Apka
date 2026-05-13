#pragma once

#include "Converter.h"



template<typename T>
class MMemory
{
    private:
       std::vector<T> MMem;
    public:
      MMemory<T>(std::vector<T> Mem):MMem{Mem} {}
      void SetMemory(std::vector<T> &MEm) {MMem = MEm;}
      std::vector<T> GetMemory() {return MMem;}
      std::vector<T> GetMemoryAt(uint16_t Index,uint16_t Lenght);
      
};

