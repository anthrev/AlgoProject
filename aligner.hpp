#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Aligner {
public:
struct Data {
		vector<int> optPathA;
		vector<int> optPathB;
		int height;
	};
    Aligner(vector<int> A_in, vector<int> B_in, int x_in, int y_in);
    int max_elem(vector<int> vec);
    int min_elem(vector<int> vec);
    Data opt_height(vector<int> A, vector<int> B);
    void print_vec(vector<int> a, vector<int> b);
    void print_arr();
private:
    vector<int> A;
    vector<int> B;
    vector<vector<Data>> arr;
};
