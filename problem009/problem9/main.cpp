//
//  main.cpp
//  problem9
//
//  Created by Gareth George on 9/7/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    for (int a = 1; a < 1000; ++a) {
        for (int b = a + 1; b < 1000 - a; ++b) {
            double c = sqrt(a*a + b*b);
            if (c != floor(c)) continue;
            
            if (a + b + c == 1000) {
                std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
                std::cout << "Product: " << a * b * (int)c << std::endl;
            }
        }
    }
    return 0;
}
