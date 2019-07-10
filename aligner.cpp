#include "aligner.hpp"

Aligner::Aligner(vector<int> A_in, vector<int> B_in, int x_in, int y_in) {
    // add arrays to Aligner object
    A = A_in;
    B = B_in;

    // create lookup table; fill with sentinel values -1
	Data data;
	data.height = -1;
    vector<Data> temp(y_in, data);
    vector<vector<Data>> temp2(x_in, temp);
    arr = temp2;
}

Data Aligner::opt_height (vector<int> A, vector<int> B) {
    int i = A.size() - 1;
    int j = B.size() - 1;

    // memoized check
    if (arr[i][j].height != -1) {
        return arr[i][j].height;
    }

    // base case: each array contains 1 element
    else if (i == 0 && j == 0) {
		arr[i][j].optPathA.push_back(A.at(0));
		arr[i][j].optPathB.push_back(B.at(0));
		arr[i][j].height = A.at(0) + B.at(0);
    }

    // base case: first array contains 1 element
    else if (i == 0) {
		arr[i][j].optPathA.push_back(A.at(0));
		arr[i][j].optPathB.push_back(max_elem(B));
        arr[i][j].height = A.at(0) + max_elem(B);
    }

    // base case: second array contains 1 element
    else if (j == 0) {
		arr[i][j].optPathA.push_back(max_elem(A));
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
		arr[i][j].height = max(w, min_elem(temp));
		switch(min_elem(temp)){
		case x.height: 
		arr[i][j].optPathA = (x.optPathA).push_back(A.at(0));
		arr[i][j].optPathB = (x.optPathB).push_back(B.at(0));
		break;
		case y.height:
		arr[i][j].optPathA = (y.optPathA).push_back(A.at(0));
		arr[i][j].optPathB = (y.optPathB).push_back(B.at(0));
		break;
		case z.height:
		arr[i][j].optPathA = (z.optPathA).push_back(A.at(0));
		arr[i][j].optPathB = (z.optPathB).push_back(B.at(0));
		break;
		}
    }

    cout << "[" << i << ", " << j << "] = " << arr[i][j].height << endl;   // DELETE later

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
       {cout << setw(2) << arr[i][j].height << " ";
       cout << endl;
	   }
    }
}

void Aligner::print_vec (vector<int> a, vector<int> b) {
    for (auto i : a) {
        std::cout << i << " ";
        cout << "; ";
    }

    for (auto i : b) {
        std::cout << i << " ";
        cout << "; ";
    }

    cout << endl;
}
