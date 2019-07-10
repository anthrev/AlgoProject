#include "aligner.hpp"

#include <algorithm>

Aligner::Aligner(vector<int> A_in, vector<int> B_in, int x_in, int y_in) {
    // add arrays to Aligner object
    A = A_in;
    B = B_in;
    print_vec(A, B);
    if(A.size() < B.size())
    {
        extendA();
    }
    else if(A.size() > B.size())
    {
        extendB();
    }

    // create lookup table; fill with sentinel values -1
	Data data;
	data.height = -1;
    vector<Data> temp(B.size(), data);
    vector<vector<Data>> temp2(A.size(), temp);
    arr = temp2;
}

void Aligner::extendA()
{
    size_t min = 0;
    for(size_t i = 1; i < A.size(); i++)
    {
        if(A.at(min)> A.at(i)) min = i;
    }

    cout << "Inserting " << B.size() - A.size() << " " << A.at(min) << endl;
    
    A.insert(A.begin()+min, B.size() - A.size(), A.at(min));
}

void Aligner::extendB()
{
    size_t min = 0;
    for(size_t i = 1; i < B.size(); i++)
    {
        if(B.at(min)> B.at(i)) min = i;
    }

    cout << "Inserting " << A.size() - B.size() << " " << B.at(min) << endl;
    
    B.insert(B.begin()+min, A.size() - B.size(), B.at(min));

}

Data Aligner::opt_height (vector<int> A, vector<int> B) {
    int i = A.size() - 1;
    int j = B.size() - 1;

    

    // memoized check
    if (arr[i][j].height != -1) {
        return arr[i][j];
    }

    // base case: each array contains 1 element
    else if (i == 0 && j == 0) {
		arr[i][j].optPathA.push_back(A.at(0));
		arr[i][j].optPathB.push_back(B.at(0));
		arr[i][j].height = A.at(0) + B.at(0);
    }

    // base case: first array contains 1 element
    else if (i == 0) {
        arr[i][j].optPathA = arr[i][j-1].optPathA;
        arr[i][j].optPathB = arr[i][j-1].optPathB;
		arr[i][j].optPathA.push_back(A.at(0));
		arr[i][j].optPathB.push_back(B.at(0));
        arr[i][j].height = A.at(0) + max_elem(B);
    }

    // base case: second array contains 1 element
    else if (j == 0) {
        arr[i][j].optPathA = arr[i-1][j].optPathA;
        arr[i][j].optPathB = arr[i-1][j].optPathB;
		arr[i][j].optPathA.push_back(A.at(0));
		arr[i][j].optPathB.push_back(B.at(0));
        arr[i][j].height = B.at(0) + max_elem(A);
    }

    // recursive calls
    else {
        vector<int> a = A;
        vector<int> b = B;
        a.erase(a.begin());     // row A minus one element
        b.erase(b.begin());     // row B minus one elements

        int w = A.at(0) + B.at(0);
        Data x = opt_height(a, b);   // both arrays shortened (up-left movement)
        Data y = opt_height(A, b);   // second array shortened (upward movement)
        Data z = opt_height(a, B);   // first array shortened (left movement)

        vector<int> temp = {x.height, y.height, z.height};
        int minTemp = min_elem(temp);
		arr[i][j].height = max(w, minTemp);

        if(minTemp == x.height)
        {
            arr[i][j].optPathA = (x.optPathA);
            arr[i][j].optPathB = (x.optPathB);
        }
        else if(minTemp == y.height)
        {
            arr[i][j].optPathA = (y.optPathA);
            arr[i][j].optPathB = (y.optPathB);
        }
        else if(minTemp == z.height)
        {
            arr[i][j].optPathA = (z.optPathA);
            arr[i][j].optPathB = (z.optPathB);
        }
        else
        {
            arr[i][j].optPathA = (x.optPathA);
            arr[i][j].optPathB = (x.optPathB);
        }

        arr[i][j].optPathA.push_back(A.at(0));
        arr[i][j].optPathB.push_back(B.at(0));
        
        
        
    
    }

    cout << "[" << i << ", " << j << "] = " << arr[i][j].height << endl;   // DELETE later
    print_vec(arr[i][j].optPathA, arr[i][j].optPathB);

    return arr[i][j];
}

/* helpers */

int Aligner::max_elem(vector<int> vec) {
    int max = vec.at(0);
    for (auto i : vec) {
        if (i > max)
            max = i;
    }
    return max;
}

int Aligner::min_elem(vector<int> vec) {
    int min = vec.at(0);
    for (auto i : vec) {
        if (i < min)
            min = i;
    }
    return min;
}

void Aligner::print_arr() {
    for(size_t i=0; i<arr.size(); i++) {
       for (size_t j=0; j<arr[i].size(); j++)
       {
           cout << setw(2) << arr[i][j].height << " ";
	   }
       cout << endl;
    }
}

void Aligner::print_vec (vector<int> a, vector<int> b) {
    for (auto i : a) {
        std::cout << i << " ";
    }

    cout << endl;

    for (auto i : b) {
        std::cout << i << " ";
    }

    cout << endl;
}
