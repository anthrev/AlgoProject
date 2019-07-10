#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Data {
		vector<int> optPathA;
		vector<int> optPathB;
		int height;
	};

class Aligner {
public:

    Aligner(vector<int> A_in, vector<int> B_in, int x_in, int y_in);
    int max_elem(vector<int> vec);
    int min_elem(vector<int> vec);
    Data opt_height(vector<int> A, vector<int> B);
    void print_vec(vector<int> a, vector<int> b);
    void print_arr();
    void extendA();
    void extendB();
    vector<int> getA() {return A;}
    vector<int> getB() {return B;}
private:
    vector<int> A;
    vector<int> B;
    vector<vector<Data>> arr;
};
