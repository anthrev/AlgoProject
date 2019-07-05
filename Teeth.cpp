#include "Teeth.hpp"

void Teeth::extend(int index)
{
    for(int i = teeth.size(); i > index; i--)
    {
        teeth[i] = teeth[i-1];
    }
}

int Teeth::getSmallestIndex()
{
    int min = 0;
    for(int i = 1; i < teeth.size(); i++) if(teeth[min] > teeth[i]) min = i;
    return min;
}