//
//  main.cpp
//  problem25
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <vector>
#include "InfInt.h"
using namespace std;


InfInt raceToAThousand(int index, InfInt& a, InfInt& b) {
    if (b.toString().size() >= 1000)
        return index;
    InfInt c = a + b;
    return raceToAThousand(index + 1, b, c);
};

int main(int argc, const char * argv[]) {
    std::cout << "Euler Problem 25 by thelastpenguin" << std::endl;
    
    InfInt one(1);
    
    std::cout << raceToAThousand(2, one, one);
    
    return 0;
}
