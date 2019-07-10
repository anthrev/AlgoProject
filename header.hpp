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

#endif /* HEADER_H */
