//
//  main.cpp
//  problem12
//
//  Created by Gareth George on 9/10/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>

typedef unsigned long number;

int numDivisors(number n) {
    int divisors = 0;
    for (number i = 1; i < n; ++i)
        if (n % i == 0)
            divisors++;
    return divisors;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Euler Problem 12" << std::endl;
    
    number counter = 0;
    number triangle = 0;
    number maxDivisors = 0;
    while (true) {
        counter++;
        triangle += counter;
        int divisors;
        if ((divisors = numDivisors(triangle)) > 500)
            break;
        if (divisors > maxDivisors) {
            std::cout << "Reached " << divisors << " divisors" << std::endl;
            maxDivisors = divisors;
        }
        
    }
    
    std::cout << "The first triangle number with over 500 divisors is: " << triangle << std::endl;
    
    return 0;
}
