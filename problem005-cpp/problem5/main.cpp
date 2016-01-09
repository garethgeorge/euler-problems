//
//  main.cpp
//  problem5
//
//  Created by Gareth George on 9/6/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

using namespace std;

inline bool isPrime(int n) {
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void primeFactorization(int n, std::unordered_map<int, int>& result) {
    unordered_map<int, int> factors;
    
    // find prime factors
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            while (n % i == 0) {
                factors[i] += 1;
                n /= i;
            }
        }
    }
    
    // merge them
    for (auto factor : factors) {
        result[factor.first] = max(result[factor.first], factor.second);
    }
}

int main(int argc, const char * argv[]) {
    std::unordered_map<int, int> factors;
    
    for (int i = 2; i <= 20; ++i) {
        primeFactorization(i, factors);
    }
    
    
    int multiples = 1;
    for (auto factor : factors) {
        std::cout << "Factor: " << "(" << factor.first << "," << factor.second << ")" << endl;
        multiples *= pow(factor.first, factor.second);
    }
    
    std::cout << "Problem: https://projecteuler.net/problem=5" << endl;
    std::cout << "Smallest Number: " << multiples << endl;
    
    return 0;
}
