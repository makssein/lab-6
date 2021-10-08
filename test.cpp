#include <iostream>
#include <fstream>
#include <math.h>
#include <climits>
#include "functions.hpp"

#define N 100
#define M 100



int main () {
    int matrix[N][M];
    int n, m;
    int maxPrime = 0;
    int minElStolb = INT_MAX;
    int minElStroka = INT_MAX;
    int test;
    
    bool check = false;
    bool checkPr = true;
    
    std::ifstream in("input.txt"); 
    std::ofstream out("output.txt");
    
    in >> n >> m;    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            in >> matrix[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == matrix[i+1][j]){
                check = true;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (matrix[i][j] >= 2){
                for (int d = 2; d <= matrix[i][j]; d++){
                    if(matrix[i][j] % d == 0)
                        checkPr = false;
                    if(checkPr){
                        if(matrix[i][j] > maxPrime)
                            maxPrime = matrix[i][j];
                    }
                        
                }
            }
        }
    }
    
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(matrix[i][j] < minElStolb){
                minElStolb = j;
                minElStroka = i;
            }
        }
        if(check){
            matrix[minElStroka][minElStolb] = maxPrime;
            minElStolb = INT_MAX;
            minElStroka = INT_MAX;
        }
        
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            out << matrix[i][j] << " ";
        }
        out << std::endl;
    }


  return 0;
}
