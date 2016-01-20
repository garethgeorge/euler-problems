//
//  main.cpp
//  problem10
//
//  Created by Gareth George on 9/7/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>

#define NUMBER 2000001


int main() {

    bool primes[NUMBER];
    for(int i = 0; i < NUMBER; ++i) {
        primes[i] = true;
    }
    
    int p = 1;
    while (true) {
        p++;
        if (p >= NUMBER)
            break;
        if (primes[p] == true) {
            for (int i = p * 2; i < NUMBER; i += p)
                primes[i] = false;
        }
    }
    
    long sum = 0;
    for (int i = 2; i < NUMBER; ++i) {
        if (primes[i] == true)
            sum += i;
    }
    
    std::cout << "Sum of primes below 2,000,000: " << sum << std::endl;
    
    return 0;
}
