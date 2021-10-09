/*
Вариант-3.
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если в матрице есть две одинаковых строки, 
заменить минимальные элементы столбцов на наибольший 
из простых элементов матрицы.
*/


#include <iostream>
#include <fstream>
#include <math.h>
#include <climits>
#include "functions.hpp"

#define N 100
#define M 100



int main() {
	int matrix[N][M];
	int n, m;
	bool checkPr = true;

	
	func::Read(n, m, matrix);
	int maxPrime = func::maxPrimeFunc(n, m, checkPr, matrix);
	func::ReplaceElements(n, m, matrix, maxPrime);
	func::write(n, m, matrix);




	return 0;
}
