#pragma once

#define N 100
#define M 100
namespace func {
	void Read(int& n, int& m, int matrix[N][M]);
	bool Checking(int& n, int& m, int matrix[N][M]);
	bool isPrime(int x);
	int maxPrimeFunc(int& n, int& m, bool& checkPr, int matrix[N][M]);
	void ReplaceElements(int& n, int& m, int matrix[N][M], int& maxPrime);
	void write(int& n, int& m, int matrix[N][M]);
}
