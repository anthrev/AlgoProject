#include <iostream>
#include <algorithm>

#include "aligner.hpp"
#include "header.hpp"

int main() {
    int x = 0;
    int y = 0;
	int z = 0;
	vector<int> Trash;
    vector<int> B;
    vector<int> C;

    read_file("input.txt", Trash, B, C, x, y, z);

    Aligner A(B, C, x, y);

    Data ans = A.opt_height(A.getA(), A.getB());
    cout << "OPTIMAL HEIGHT: " << ans.height << endl;  // DELETE later
	cout << "OPTIMAL PATH: " << endl;
	reverse(ans.optPathA.begin(), ans.optPathA.end());
	reverse(ans.optPathB.begin(), ans.optPathB.end());
	write_file(ans.optPathA, ans.optPathB,ans.height);
	
	for(size_t i=0; i< ans.optPathA.size(); i++){
		cout << ans.optPathA[i] << " ";
	}
	cout << endl;
	for(size_t i=0; i< ans.optPathB.size(); i++){
		cout << ans.optPathB[i] << " ";
	}
	cout << endl;
    A.print_arr();                              // DELETE later
}
