//
//  main.cpp
//  problem20
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include "InfInt.h"

using namespace std;

InfInt factorial(int n) {
    InfInt start(1);
    for (int i = n; i > 1; i--) {
        start *= i;
    }
    return start;
}

int main(int argc, const char * argv[]) {
    std::cout << "Euler Problem 20 by thelastpenguin" << std::endl;
    
    InfInt fact100 = factorial(100);
    string strFact100 = fact100.toString();
    const char* charFact100 = strFact100.c_str();
    
    int digitSum = 0;
    for (int i = 0; i < strFact100.size(); ++i) {
        digitSum += charFact100[i] - '0';
    }
    
    std::cout << "The sum of the digits in 100! is " << digitSum << endl;
    
    return 0;
}
