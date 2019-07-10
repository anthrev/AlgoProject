#include <iostream>

#include "aligner.hpp"
#include "header.hpp"

int main() {
    int x = 0;
    int y = 0;
    vector<int> B;
    vector<int> C;

    read_file("input.txt", B, C, x, y);

    Aligner A(B, C, x, y);

    Aligner::Data ans = A.opt_height(B, C);
    cout << "OPTIMAL HEIGHT: " << ans.height << endl;  // DELETE later
	cout << "OPTIMAL PATH: " << endl;
	for(size_t i=ans.optPathA.size() - 1; i> -1; i--){
		cout << ans.optPathA[i] << " ";
	}
	cout << endl;
	for(size_t i=ans.optPathB.size() - 1; i> -1; i--){
		cout << ans.optPathB[i] << " ";
	}
	cout << endl;
    A.print_arr();                              // DELETE later
}
