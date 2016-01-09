#include <stdio.h>
#include <iostream>

int main() {
	int sum = 0;
	std::cout << "Finding the sum of all multiples of 3 or 5 below 1000." << std::endl;
	for (int i = 0; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	std::cout << "\tSum: " << sum << std::endl;


	char wait;
	std::cin >> wait;
}