//
//  main.cpp
//  problem24
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long num;

template<int COUNT>
class permutations
{
public:
    static void run(std::vector<num>& res, num prefix, char digits[COUNT])
    {
        prefix *= 10;
        for (int i = 0; i < COUNT; ++i) {
            
            char buff[COUNT - 1];
            
            for (int j = 0; j < i; ++j)
                buff[j] = digits[j];
            for (int j = i; j < COUNT - 1; ++j)
                buff[j] = digits[j+1];
            
            permutations<sizeof(buff) / sizeof(char)>::run(res, (num) (prefix + digits[i]), buff);
        }
    }
};

template<>
class permutations<0>
{
public:
    static void run(std::vector<num>& res, num prefix, char digits[0])
    {
        res.push_back(prefix);
    }
};


int main(int argc, const char * argv[]) {
    
    
    
    std::vector<num> res;
    
    char digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    permutations<sizeof(digits) / sizeof(char)>::run(res, 0, digits);
    
    std::sort(res.begin(), res.end());
    
    std::cout << "The millionth lexographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 is: " << res[1000000 - 1];
    
    return 0;
}
