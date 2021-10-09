#pragma once
#include "functions.hpp"
#include <fstream>

#define N 100
#define M 100
namespace func {
	void Read(int& n, int& m, int matrix[N][M]) {
		std::ifstream in("input.txt");
		in >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				in >> matrix[i][j];
			}
		}
	}
	bool Checking(int& n, int& m, int matrix[N][M]) {
		for (int i = 0; i < n; i++) {
			int b = 0;
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == matrix[i + 1][j]) {
					b += 1;
				}
			}
			if (b == m) {
				return true;
			}
		}
		return false;
	}
	bool isPrime(int x) {
		if (x < 2)
			return false;
		for (int d = 2; d <= sqrt(x); d++)
			if (x % d == 0)
				return false;
		return true;
	}
	int maxPrimeFunc(int n, int m, bool& checkPr, int matrix[N][M]) {
		int maxPrime = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				checkPr = true;
				if (isPrime(matrix[i][j]) && matrix[i][j] > maxPrime) {
					maxPrime = matrix[i][j];
				}
			}
		}
		return maxPrime;
	}
	void ReplaceElements(int n, int m, int matrix[N][M], int maxPrime) {
		int minElStolb = N;
		int minElStroka = M;
		int test = INT_MAX;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				if (matrix[i][j] < test) {
					minElStolb = j;
					minElStroka = i;
					test = matrix[i][j];
				}
			}
			if (func::Checking(n, m, matrix)) {
				matrix[minElStroka][minElStolb] = maxPrime;
				minElStolb = N;
				minElStroka = M;
			}
			test = INT_MAX;

		}
	}

	void write(int& n, int& m, int matrix[N][M]) {
		std::ofstream out("output.txt");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				out << matrix[i][j] << " ";
			}
			out << std::endl;
		}
	}
}
