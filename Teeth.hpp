#ifndef TEETH_HPP
#define TEETH_HPP

#include <vector>

class Teeth
{
    public:
        Teeth() = default;
        Teeth(std::vector<int> t) {teeth = t;}

        void extend(int);
        int getHeight(int x) {return teeth[x];}
        int getSmallestIndex();

    private:
        std::vector<int> teeth;

};

#endif