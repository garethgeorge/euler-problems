//
//  main.cpp
//  problem4
//
//  Created by Gareth George on 9/6/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdint.h>

using namespace std;

typedef uint32_t big;

big reverse(big number) {
    big output = 0;
    while(number > 0) {
        output = output * 10 + number % 10;
        number /= 10;
    }
    return output;
}

bool isPalendrome(big num) {
    return num == reverse(num);
}

int main(int argc, const char * argv[]) {
    big biggest = 0;
    for(big i = 100; i < 1000; ++i) {
        for(big b = i; b < 1000; ++b) {
            big product = i * b;
            if (isPalendrome(product)) {
                if (product > biggest)
                    biggest = product;
            }
        }
    }
    
    std::cout << "Biggest: " << biggest << endl;
    return 0;
}
