#ifndef TA_HPP
#define TA_HPP

#include "Teeth.hpp"

#include <vector>
#include <string>
#include <fstream>


class TA
{
    public:
        TA() = default;
        TA(Teeth x, Teeth y) {A = x; B = y;}

        
        void align();
        void printToFile(std::string);
    
    private:
        int optH;
        Teeth A, B;

};

#endif