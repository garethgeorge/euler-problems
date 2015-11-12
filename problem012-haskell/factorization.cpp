#include <iostream>
#include <algorithm>
using namespace std;

int factorCount(int n) {
	int c = 0;
	for (int i = 1; i*i <= n; ++i)
		if (n % i == 0)
			c++;
	return c*2;
}

int fitz(int val, int prime)

int main () {
	int i = 1;
	while (factorCount(i) < 500) {
		i++;
	}
	std::cout << i << std::endl;
}
