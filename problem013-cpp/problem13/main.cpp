#include <iostream>
#include <math.h>
#include "InfInt.h"
#include <fstream>

using namespace std;


int main() {
    cout << "Problem 13" << endl;
    InfInt sum("0");
    
    ifstream data("/Volumes/GARETH G/git/euler/problem13/input.txt");
    
    for (int i = 0; i < 100; ++i) {
        string nextNumber;
        data >> nextNumber;
        
        sum += InfInt(nextNumber);
    }
    
    cout << "Sum of 100x 50 digit numbers: " << sum.toString().substr(0, 10);
}