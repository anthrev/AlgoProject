#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_file (string file_name, vector<int> &A, vector<int> &B, int &x, int &y) {
    int temp;
    std::string line;
    std::ifstream infile(file_name);

    std::getline(infile, line);
    std::istringstream iss(line);
    while (iss >> temp) {
        A.push_back(temp);
        x++;
    }

    std::getline(infile, line);
    std::istringstream iss2(line);
    while (iss2 >> temp) {
        B.push_back(temp);
        y++;
    }
}

void write_file (vector<int> &A, vector<int> &B, int &h) {
    std::ofstream out;
	out.open("output.txt");
	out << h << endl;
	for(size_t i=0; i< A.size(); i++){
		out << A[i] << " " << B[i] << endl;
	}
    out.close();
}
#endif /* HEADER_H */
