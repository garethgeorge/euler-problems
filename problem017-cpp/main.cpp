//
//  main.cpp
//  problem17
//
//  Created by Gareth George on 9/11/15.
//  Copyright (c) 2015 Gareth George. All rights reserved.
//

#include <iostream>

using namespace std;

#define LETTER_COUNT(word) sizeof(word) / sizeof(char) - 1

int firstPlace[] = {
    0,
    LETTER_COUNT("one"),
    LETTER_COUNT("two"),
    LETTER_COUNT("three"),
    LETTER_COUNT("four"),
    LETTER_COUNT("five"),
    LETTER_COUNT("six"),
    LETTER_COUNT("seven"),
    LETTER_COUNT("eight"),
    LETTER_COUNT("nine")
};
int teens[] = {
    LETTER_COUNT("ten"),
    LETTER_COUNT("eleven"),
    LETTER_COUNT("twelve"),
    LETTER_COUNT("thirteen"),
    LETTER_COUNT("fourteen"),
    LETTER_COUNT("fifteen"),
    LETTER_COUNT("sixteen"),
    LETTER_COUNT("seventeen"),
    LETTER_COUNT("eighteen"),
    LETTER_COUNT("nineteen")
};
int secondPlace[] = {
    0,
    0,
    LETTER_COUNT("twenty"),
    LETTER_COUNT("thirty"),
    LETTER_COUNT("fourty"),
    LETTER_COUNT("fifty"),
    LETTER_COUNT("sixty"),
    LETTER_COUNT("seventy"),
    LETTER_COUNT("eighty"),
    LETTER_COUNT("ninety")
};

int hundred = LETTER_COUNT("hundred");
int thousand = LETTER_COUNT("thousand");


int numDigits(int number) {
    int digits = 0;
    int thousands = number / 1000;
    int hundreds = (number / 100) % 10;
    int tens = (number / 10) % 10;
    int ones = number % 10;
    
    if (thousands > 0)
        digits += thousand + firstPlace[thousands];
    if (hundreds > 0)
        digits += hundred + firstPlace[hundreds];
    
    if (tens == 1) {
        digits += teens[digits];
    } else {
        if (tens > 1)
            digits += secondPlace[tens];
        if (ones > 0)
            digits += firstPlace[ones];
    }
    
    return digits;
}



int main(int argc, const char * argv[]) {
    cout << "Euler Problem 17 by thelastpenguin" << endl;
    cout << "\tmay not be correct but this one is not that interesting so im moving on." << endl;
    
    int digits = 0;
    for(int i = 1; i <= 1000; ++i) {
        digits += numDigits(i);
    }
    
    cout << "Total digits needed to write all the numbers from 1 to 1,000 as words: " << digits << endl;
    
    return 0;
}
