#include "TeethAligner.hpp"


void TA::align(int a, int b, Teeth* row1, Teeth* row2)
{
    if(a != b)
    {
        if(a > b)
        {
            row1->extend(row1->getSmallestIndex());
        }
        else
        {
            row2->extend(row2->getSmallestIndex());
        }
        
    }
}