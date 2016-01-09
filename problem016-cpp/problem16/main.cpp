//
//  main.cpp
//  problem16
//
//  Created by Gareth George on 9/10/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include "InfInt.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Euler Problem 16" << endl;
    
    InfInt start(2);
    for (int i = 1; i < 1000; ++i) {
        start *= 2;
    }
    
    string digits = start.toString();
    const char* digitsRaw = digits.c_str();
    
    int sum = 0;
    for (int i = 0; i < digits.length(); ++i) {
        sum += digitsRaw[i] - '0';
    }
    
    cout << "The sum of the digits of 2 ^ 1000 is " << sum << endl;
    
    return 0;
}
