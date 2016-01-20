//
//  main.cpp
//  problem028
//
//  Created by Gareth George on 9/12/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>

#define GRID_SIZE 1001

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    
    int** grid = new int*[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; ++i)
        grid[i] = new int[GRID_SIZE];
    
    
    int counter = 1;
    
    int x = GRID_SIZE * 0.5;
    int y = GRID_SIZE * 0.5;
    
    grid[x][y] = counter++;
    
    int radius = 0;
    
    
    
    
    for (int i = 0; i < 1001; ++i)
        delete[] grid[i];
    delete[] grid;
    
    return 0;
}
