#include <stdint.h>
#include <stdio.h>
#include <iostream>

uint32_t fib(uint32_t a, uint32_t b) {
	int n = a + b;
	if (n >= 4000000)
		return 0;
	return (n % 2 == 0 ? n : 0) + fib(b, n);
}

int main() {
	std::cout << "problem 2: https://projecteuler.net/problem=2" << std::endl;
	std::cout << "Sum of even fib numbers < 4,000,000 " << std::endl;
	std::cout << fib(1, 1);

	char wait;
	std::cin >> wait;
}