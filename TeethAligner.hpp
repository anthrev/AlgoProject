#ifndef TA_HPP
#define TA_HPP

#include "Teeth.hpp"

#include <vector>

class TA
{
    public:
        TA() = default;
        TA(Teeth x, Teeth y);

        void align();
    
    private:
        std::vector<std::vector<bool>> map;

        Teeth A, B;

};

#endif