#include "TeethAligner.hpp"

#include <iostream>
#include <stack>


void TA::align()
{
    std::cout << "Starting to align" << std::endl;

    if(A.getSize() != B.getSize())
    {
        if(A.getSize() > B.getSize())
        {
            std::cout << "Extending B" << std::endl;
            while(A.getSize() > B.getSize()) B.extend(B.getSmallestIndex());
            
        }
        else
        {
            std::cout << "Extending A" << std::endl;
            while(A.getSize() < B.getSize()) A.extend(A.getSmallestIndex());
        }
    }
    
    A.print();
    B.print();

    int AxBn = A.getMax() + B.getMin();
    int AnBx = B.getMax() + A.getMin();
    int first = A.first() + B.first();
    int last = A.last() + B.last();

    int optH = std::max(std::max(AxBn,AnBx),std::max(first,last));
    std::cout << "Found optimum height " << optH << std::endl;


    std::vector< std::vector<bool> > map (A.getSize(), std::vector<bool>(B.getSize(), false));

    std::cout << "Initalized map" << std::endl;

    for( int i = 0; i < A.getSize(); i++)
    {
        for( int j = 0; j < B.getSize(); j++)
        {
            // std::cout << "i = " << i << " j = " << j << std::endl <<  " A.at(i) = " << A.getHeight(i)
            // << " B.at(i) = " << B.getHeight(j) << std::endl;
            if((A.getHeight(i)+B.getHeight(j)) > optH) map[i][j] = true;
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    Teeth newA, newB;

    int X = 0, Y = 0;

    newA.push(A.getHeight(X));
    newB.push(B.getHeight(Y));

    std::stack<int> path;

    std::cout << "Entering while loop" << std::endl;

    while(X != A.getSize()-1 || Y != B.getSize()-1)
    {
        std::cout << "X = " << X << " Y = " << Y << std::endl;
        
        if(X == A.getSize()-1) X--;
        if(Y == A.getSize()-1) Y--;

        if(!map[X+1][Y+1])
        {
            X++;
            Y++;
            newA.push(A.getHeight(X));
            newB.push(B.getHeight(Y));
            path.push(1);
            
        }
        else if (!map[X+1][Y])
        {
            X++;
            newA.push(A.getHeight(X));
            newB.push(B.getHeight(Y));
            path.push(2);
        }
        else if (!map[X][Y+1])
        {
            Y++;
            newA.push(A.getHeight(X));
            newB.push(B.getHeight(Y));
            path.push(3);
        }
        else
        {
            std::cout << "Backtracking" << std::endl;
            map[X][Y] = true;
            switch (path.top())
            {
            case 1:
                X--;
                Y--;
                break;
            case 2:
                X--;
                break;
            case 3:
                Y--;
                break;
            default:
                break;
            }
            path.pop();
            newA.pop();
            newB.pop();
        }
        

        
        newA.print();
        newB.print();
        
        
    }

    
}