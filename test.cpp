#include <iostream>
#include <fstream>
#include <math.h>
#include <climits>
#include "functions.hpp"

#define N 100
#define M 100



int main () {
    int matrix[N][M];
    int n, m, b;
    b=0;
    int maxPrime = 0;
    int minElStolb = INT_MAX;
    int minElStroka = INT_MAX;
    int test = INT_MAX;
    
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
                b+=1;
            }
        }
        if(check && b==m)
            check = true;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            checkPr = true; 
            if (matrix[i][j] >= 2){
                for (int d = 3; d < matrix[i][j]; d++)
                    if(matrix[i][j] % d == 0){
                        checkPr = false; break; 
                    }
                if(checkPr){
                    if(matrix[i][j] > maxPrime)
                        maxPrime = matrix[i][j];
                }
            }
        }
    }
    
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(matrix[i][j] < test){
                minElStolb = j;
                minElStroka = i;
                test = matrix[i][j];
            }
        }
        if(check && b==m){
            matrix[minElStroka][minElStolb] = maxPrime;
            minElStolb = INT_MAX;
            minElStroka = INT_MAX;
        }
        std::cout << test << std::endl;
        test = INT_MAX;
        
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            out << matrix[i][j] << " ";
        }
        out << std::endl;
    }
    
    


  return 0;
}
