#include <fstream>
#include <iostream>
#include <vector>

#include "TeethAligner.hpp"

int main()
{
    std::ifstream ifs;
    ifs.open("input.txt");

    int n, m, x;
    ifs >> n >> m;

    std::vector<int> A, B;

    for(int i = 0; i < n; i++)
    {
        ifs >> x;
        A.push_back(x);
    }

    for(int i = 0; i < m; i++)
    {
        ifs >> x;
        B.push_back(x);
    }
    Teeth row1(A);
    Teeth row2(B);


    TA aligner(row1, row2);

    aligner.align();

    // TODO: print to output file 

    return 0;
}