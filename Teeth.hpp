#ifndef TEETH_HPP
#define TEETH_HPP

#include <vector>
#include <iostream>

class Teeth
{
    public:
        Teeth() = default;
        Teeth(std::vector<int> t) {teeth = t;}

        void extend(int);
        int getHeight(int x) {return teeth[x];}
        int getSmallestIndex();

        void print() { for(int i=0;i< teeth.size(); i++) std::cout << teeth[i] << " "; std::cout << std::endl;}

    private:
        std::vector<int> teeth;

};

#endif