//
//  main.cpp
//  problem7
//
//  Created by Gareth George on 9/7/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    int max = ceil(sqrt(n));
    for (int i = 2; i < max; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    int count = 0;
    int i = 0;
    while (count < 10001) {
        i++;
        if (isPrime(i)) {
            count++;
        }
    }
    
    std::cout << "The 10001st prime is " << i << endl;
    
    return 0;
}
