#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "benchmarking.h"
#define MAX_LENGTH 1500000

using std::string;
using std::stringstream;
using std::vector;

template<int cols, int rows>
class Matrix {
public:
	int data[cols][rows];

	Matrix() {
		for (int x = 0; x < cols; ++x)
			for (int y = 0; y < rows; ++y)
				data[x][y] = 0;
	}

	Matrix(int data[rows][cols]) {
		for (int x = 0; x < cols; ++x)
			for (int y = 0; y < rows; ++y)
				this->data[x][y] = data[y][x];
	}

	template<int cols2, int rows2> 
	Matrix<cols2, rows> mult(Matrix<cols2,rows2>& other) {
		Matrix<cols2, rows> result;
		for (int a = 0; a < rows; ++a) {
			for (int b = 0; b < cols2; ++b) {
				int total = 0;
				for (int c = 0; c < cols; ++c) {
					total += this->data[c][a] * other.data[b][c];
				}
				result.data[b][a] = total;
			}
		}
		return result;
	}

	string toString() {
		stringstream out;
		for (int y = 0; y < rows; ++y) {
			out << "[";
			for (int x = 0; x < cols; ++x) {
				out << data[x][y] << ",";
			}
			out << "]" << std::endl;
		}
		return out.str();
	}
};


int init_root[3][1] = {{3}, {4}, {5}};
int init_A[3][3] = {
	{1, -2, 2},
	{2, -1, 2},
	{2, -2, 3}
};
int init_B[3][3] = {
	{1, 2, 2},
	{2, 1, 2},
	{2, 2, 3}
};
int init_C[3][3] = {
	{-1, 2, 2},
	{-2, 1, 2},
	{-2, 2, 3}
};

Matrix<1,3> root(init_root);
Matrix<3,3> A(init_A);
Matrix<3,3> B(init_B);
Matrix<3,3> C(init_C);

void findRecursive(Matrix<1, 3> parent, int* lengthBuckets, int maxLength) {
	int length = parent.data[0][0] + parent.data[0][1] +  parent.data[0][2];
	if (length >= maxLength)
		return ;

	// also add primatives.
	for (int i = length; i < maxLength; i += length)
		lengthBuckets[i]++;

	findRecursive(A.mult(parent), lengthBuckets, maxLength);
	findRecursive(B.mult(parent), lengthBuckets, maxLength);
	findRecursive(C.mult(parent), lengthBuckets, maxLength);
}

int main() {

	benchmark b;

	int* lengthBuckets = new int[MAX_LENGTH];
	for (int i = 0; i < MAX_LENGTH; ++i)
		lengthBuckets[i] = 0;

	findRecursive(root, lengthBuckets, MAX_LENGTH);

	int counts = 0;
	for (int i = 0; i < MAX_LENGTH; ++i)
		if (lengthBuckets[i] == 1)
			counts++;
	std::cout << "Answer: " << counts << std::endl;
	std::cout << "Took: " << b.end() << std::endl;
}