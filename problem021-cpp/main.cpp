//
//  main.cpp
//  problem21
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <unordered_set>

#define COUNT 10000

using namespace std;

int dCache[COUNT + 1];

inline int d(int n) {
    if (dCache[n] > 0)
        return dCache[n];
    
    int s = 0;
    
    for (int i = 1; i < n; ++i) {
        if (n % i == 0)
            s += i;
    }
    
    return dCache[n] = s;;
}

inline bool isAmicable(int a, int b) {
    return d(a) == b && d(b) == a;
}

int main(int argc, const char * argv[]) {
    cout << "Euler Problem 21 by Gareth George" << endl;
    
    for (int i = 0; i < COUNT; i++) {
        dCache[i] = 0;
    }
    
    unordered_set<int> numbers;
    for (int a = 1; a <= COUNT; a++) {
        for (int b = a + 1; b <= COUNT; b++) {
            if (isAmicable(a, b)) {
                numbers.insert(a);
                numbers.insert(b);
            }
        }
    }
    
    int sum = 0;
    for (auto val : numbers) {
        sum += val;
    }
    
    cout << "Sum of amacable numbers: " << sum << endl;

    return 0;
}
