#ifndef TA_HPP
#define TA_HPP

#include "Teeth.hpp"

#include <vector>

class TA
{
    public:
        TA() = default;

        void align(int, int, Teeth*, Teeth*);
    
    private:
        std::vector<int> map;

        int n, m;
        Teeth A, B;

};

#endif