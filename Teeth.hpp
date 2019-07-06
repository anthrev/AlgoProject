#ifndef TEETH_HPP
#define TEETH_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Teeth
{
    public:
        Teeth() = default;
        Teeth(std::vector<int> t) {teeth = t;}

        void extend(int);
        int getHeight(int x) {return teeth[x];}
        int getSmallestIndex();
        int getMin() {return *std::max_element(teeth.begin(), teeth.end());}
        int getMax() {return *std::min_element(teeth.begin(), teeth.end());}
        int getSize() {return teeth.size();}

        void print() { for(int i=0;i< teeth.size(); i++) std::cout << teeth[i] << " "; std::cout << std::endl;}

    private:
        std::vector<int> teeth;

};

#endif