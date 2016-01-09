//
//  main.cpp
//  problem6
//
//  Created by Gareth George on 9/6/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>

int abs(int a) {
    return a > 0 ? a : -a;
}

int main(int argc, const char * argv[]) {
    int a = 0;
    int b = 0;
    for (int i = 1; i <= 100; ++i) {
        a += i * i;
        b += i;
    }
    b *= b; // b ^ 2;
    
    std::cout << "sum of squares - square of sum: " << abs(a - b);
    return 0;
}
