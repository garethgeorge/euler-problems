//
//  main.cpp
//  problem23
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <vector>

#define UPPER_BOUND 28123

using namespace std;

inline bool sumDivisors(int n) {
    int s = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0)
            s += i;
    }
    return s;
}

inline bool isAbundant(int n) {
    return sumDivisors(n) > n;
}


int main(int argc, const char * argv[]) {
    
    vector<int> abundant;
    for (int i = 0; i < UPPER_BOUND; ++i) {
        if (isAbundant(i))
            abundant.push_back(i);
    }
    
    bool abundantSums[UPPER_BOUND];
    
    for (int i = 0; i < UPPER_BOUND; ++i)
        abundantSums[i] = false;
    
    for (auto a = abundant.begin(); a < abundant.end(); ++a) {
        for (auto b = a; b < abundant.end(); ++b) {
            if (*a + *b >= UPPER_BOUND)
                continue;
            abundantSums[*a + *b] = true;
        }
    }
    
    int total = 0;
    for (int i = 12; i < UPPER_BOUND; ++i) {
        if (abundantSums[i] == false)
            total += i;
    }
    cout << "total: " << total;
    
    return 0;
}
