//
//  main.cpp
//  problem18
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<int>> triangle;


template<typename A>
A myMax(A a, A b) {
    return a > b ? a : b;
}


int bigSum(triangle& tri, int row, int col) {
    if (row == tri.size())
        return 0;
    
    return tri[row][col] + myMax(
            bigSum(tri, row + 1, col),
            bigSum(tri, row + 1, col + 1)
        );
}

void printTriangle(triangle& tri) {
    for (auto row : tri) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}


int main(int argc, const char * argv[]) {
    
    triangle triangle;
    
    ifstream data("/Volumes/GARETH G/git/euler/problem18/triangle.txt");
    triangle.push_back(vector<int>());
    
    while(true) {
        string read;
        data >> read;
        
        if (read == "\\") {
            triangle.push_back(vector<int>());
        } else if (read == "END") {
            break ;
        } else {
            triangle[triangle.size() - 1].push_back(std::stoi(read));
        }
    }
    
    printTriangle(triangle);
    cout << "Triangle sum: " << bigSum(triangle, 0, 0) << endl;
    
    return 0;
}
