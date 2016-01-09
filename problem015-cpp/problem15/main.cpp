//
//  main.cpp
//  problem15
//
//  Created by Gareth George on 9/10/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <unordered_map>

#define GRID_W 20
#define GRID_H 20

using namespace std;

#define ENCODE_POS(x, y) x * (GRID_W + 1) + y


unordered_map<long, long> cache;

long gridSize(int x, int y) {
    if (x == 0 && y == 0)
        return 1;
    
    if (cache[ENCODE_POS(x, y)])
        return cache[ENCODE_POS(x, y)];
    
    long paths = 0;
    
    if (x > 0)
        paths += gridSize(x - 1, y);
    if (y > 0)
        paths += gridSize(x, y - 1);
    
    cache[ENCODE_POS(x, y)] = paths;
    
    return paths;
}

int main(int argc, const char * argv[]) {
    
    cout << "Euler problem 15" << endl;
    cout << "Number of paths from the top left corner to the bottom right corner of a 20x20 grid" << endl;
    
    // 137846528820
    cout << gridSize(20, 20);
    
    return 0;
}
