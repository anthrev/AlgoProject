#include "Teeth.hpp"

void Teeth::extend(int index)
{
    int last = teeth[teeth.size() - 1];
    for(int i = teeth.size(); i > index; i--)
    {
        teeth[i] = teeth[i-1];
    }
    teeth.push_back(last);
}

int Teeth::getSmallestIndex()
{
    int min = 0;
    for(int i = 1; i < teeth.size(); i++) if(teeth[min] > teeth[i]) min = i;
    return min;
}