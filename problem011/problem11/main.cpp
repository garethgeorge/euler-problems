//
//  main.cpp
//  problem11
//
//  Created by Gareth George on 9/10/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <vector>

class IntGrid {
private:
    static const char* findNextInteresting(const char* index) {
        while (*index >= 48 && *index <= 57) {
            index++;
        }
        return index;
    }
    
    template<typename A>
    static A myMax(A a, A b) {
        if (a > b)
            return a;
        else
            return b;
    }
    
    template<typename A, typename ... Args>
    A myMax(A a, A b, Args ... args) {
        return myMax(myMax(a, b), args...);
    }
    
public:
    int columns;
    int rows;
    std::vector<std::vector<int>> numbers;
    
    IntGrid(const char* data) {
        const char* dataEnd = data + strlen(data);
        const char* index = data;
        const char* nextIndex;
        numbers.push_back(std::vector<int>());
        
        while(*(nextIndex = findNextInteresting(index)) != '\0'){
            
            if (*nextIndex == '\n' || *nextIndex == ' ') {
                int value = std::stoi(std::string(index, nextIndex));
                numbers[numbers.size() - 1].push_back(value);
            }
            
            if (*nextIndex == '\n') {
                rows++;
                numbers.push_back(std::vector<int>());
            }
            
            index = nextIndex + 1;
        }
        
        numbers.pop_back();
    }
    
    inline size_t getColumns() const {
        return numbers[0].size();
    }
    
    inline size_t getRows() const {
        return numbers.size();
    }
    
    inline int getNumber(int x, int y) {
        if (y < 0 || y >= numbers.size()) {
            std::cout << "y: " << y << std::endl;
            return 0;
        }
        if (x < 0 || x >= numbers[y].size()) {
            std::cout << "x: " << x << std::endl;
            return 0;
        }
        return numbers[y][x];
    }
    
    void print() {
        for (auto row : numbers) {
            for (auto col : row) {
                if (col == 0) {
                    std::cout << "00";
                } else if (col < 10) {
                    std::cout << "0" << col;
                } else {
                    std::cout << col;
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
    
    int getMaxProduct(int len) {
        int big = 0;
        for (int y = 0; y < getRows(); ++y) {
            for (int x = 0; x < getColumns(); ++x) {
                big = myMax(big, bigProduct(x, y, len));
            }
        }
        return big;
    }
    
    int bigProduct(int x, int y, int len) {
        return myMax<int>(
            dirProduct(x, y, 1, 0, len),
            dirProduct(x, y, 0, 1, len),
            dirProduct(x, y, -1, 0, len),
            dirProduct(x, y, 0, -1, len),
            
            dirProduct(x, y, -1, -1, len),
            dirProduct(x, y, -1, 1, len),
            dirProduct(x, y, 1, 1, len),
            dirProduct(x, y, 1, -1, len)
        );
    };
    
    int dirProduct(int x, int y, int u, int v, int len) {
        if (x + u * len < 0 || x + u * len >= getColumns()) {
            return 0;
        }
        
        if (y + v * len < 0 || y + v * len >= getRows()) {
            return 0;
            
        }
        
        int p = 1;
        
        for (int i = 0; i < len; ++i) {
            p *= getNumber(x, y);
            x += u;
            y += v;
        }
        
        return p;
    };
};

int main(int argc, const char * argv[]) {
    std::cout << "Euler problem 11" << std::endl;
    
    const char* data =
    "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\n"
    "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\n"
    "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\n"
    "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\n"
    "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\n"
    "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\n"
    "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\n"
    "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\n"
    "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\n"
    "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\n"
    "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\n"
    "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\n"
    "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\n"
    "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\n"
    "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\n"
    "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\n"
    "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\n"
    "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\n"
    "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48\n";
    
    
    IntGrid grid(data);
    grid.print();
    
    std::cout << std::endl << "Biggest Product of 4 ajacent numbers in grid: " << grid.getMaxProduct(4) << std::endl;
    
    return 0;
}
