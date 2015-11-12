//
//  main.cpp
//  problem26
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <string>


template<int ACCURACY>
void remainder(int n, char result[ACCURACY]) {
    int base = 1;
    for (int i = 0; i < ACCURACY; ++i) {
        int a = base / n;
        result[i] = a;
        base = base - a * n;
        base = base * 10;
    }
}

template<int SIZE>
int findPeriod(char* data) {
    for (int i = 1; i < SIZE / 2; ++i) {
        bool reflection = true;
        for (int j = 0; reflection && j < i; ++j) {
            int val = data[j];
            for (int k = j; k < SIZE; k += i) {
                if (val != data[k]) {
                    reflection = false;
                    break;
                }
            }
        }
        if (reflection)
            return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int longest = 0;
    int d = 0;
    for (int i = 1; i < 1000; ++i) {
        char result[10000];
        remainder<sizeof(result)/sizeof(char)>(i, result);
        int period = findPeriod<sizeof(result)/sizeof(char)-1>(result+1);
        if (period > longest) {
            longest = period;
            d = i;
        }
    }
    
    std::cout << "The d value for which the period is the longest (d < 1000) is " << d;
    
    return 0;
}
