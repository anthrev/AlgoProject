#ifndef TA_HPP
#define TA_HPP

#include "Teeth.hpp"

#include <vector>

enum dir {DIAG, DOWN, LEFT};

class TA
{
    public:
        TA() = default;
        TA(Teeth x, Teeth y) {A = x; B = y;}

        void align();
    
    private:
        Teeth A, B;

};

#endif