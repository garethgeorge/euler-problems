//
//  main.cpp
//  problem22
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool nameComparator(string& n1, string& n2) {
    return n1 < n2;
}

int alphebeticalValue(string& name) {
    int sum = 0;
    for (auto c : name) {
        sum += c - 'A' + 1;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cout << "Euler Problem 23 by thelastpenguin" << endl;
    
    // read the names
    ifstream names("/Volumes/GARETH G/git/euler/problem22/names.txt");
    
    vector<string> nameVector;
    
    while (!names.eof()) {
        string name;
        std::getline(names, name, ',');
        
        nameVector.push_back(name.substr(1, name.length() - 2));
    }
    
    // sort names alphabetically
    std::sort(nameVector.begin(), nameVector.end(), nameComparator);
    
    // output them all for debug purposes
    for (int i = 0; i < nameVector.size(); ++i) {
        std::cout << nameVector[i] << ",";
    }
    
    // calculate and total scores
    int total = 0;
    for (int i = 0; i < nameVector.size(); ++i) {
        total += (i + 1) * alphebeticalValue(nameVector[i]);
    }
    
    string testName("COLIN");
    cout << "Alphabetical Value of COLIN: " << alphebeticalValue(testName) << endl;
    cout << "Total Score: " << total << endl;
    
    
    return 0;
}
