//
//  main.cpp
//  problem27
//
//  Created by Gareth George on 9/12/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include "benchmarking.h"

#define NUMBER 2000000

using namespace std;

typedef int num;

struct equation {
    equation() : a(0), b(0) {
        
    }
    int a;
    int b;
};

inline num f(equation& eq, num n) {
    return n * n + eq.a * n + eq.b;
}

int main(int argc, const char * argv[]) {
    std::cout << "Euler Problem 27" << endl;
    
    benchmark mark;
    
    bool* primes = new bool[NUMBER];
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
    
    int bigCount = 0;
    equation bestEq;
    bestEq.a = 0;
    bestEq.b = 0;
    
    equation eq;
    eq.a = 0;
    eq.b = 0;
    for (eq.b = -1000; eq.b <= 1000; ++eq.b) {
        if (!primes[eq.b])
            continue;
        for (eq.a = -1000; eq.a <= 1000; ++eq.a) {
            int count = 0;
            while (primes[f(eq, count)]) {
                count++;
            }
            if (count > bigCount) {
                bigCount = count;
                bestEq = eq;
            }
        }
    }
    
    cout << "Biggest prime sequence: " << bigCount << endl;
    cout << "Equation terms: a = " << bestEq.a << " and b = " << bestEq.b << endl;
    cout << "Coefficient Product: " << bestEq.a * bestEq.b << endl;
    cout << "Solved in " << mark.end() << " seconds." << endl;
    
    return 0;
}
