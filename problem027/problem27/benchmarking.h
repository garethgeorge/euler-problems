//
//  benchmarking.h
//  problem27
//
//  Created by Gareth George on 9/12/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#ifndef problem27_benchmarking_h
#define problem27_benchmarking_h

#include <ctime>

class benchmark {
private:
    std::clock_t start;
    
public:
    benchmark() {
        start = std::clock();
    }
    
    double end() {
        return (std::clock() - start) / (double) CLOCKS_PER_SEC;
    }
};


#endif
