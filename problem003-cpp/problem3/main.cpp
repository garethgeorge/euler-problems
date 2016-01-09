#include <stdint.h>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	uint64_t bigNumber = 600851475143;

	uint64_t lastFactor = 0;

	for (uint64_t i = 2; i < bigNumber && bigNumber > 1; i++) {
		while(bigNumber % i == 0) {
			lastFactor = i;
			bigNumber /= i;
		}
	}
	
	cout << "Problem: " << "https://projecteuler.net/problem=3" << endl;
	cout << "Big Factor: " << lastFactor << endl;

	char wait;
	cin >> wait;
}