#include <stdio.h>

#define N 1024

// on heap (garbage values)
double A[N][N];
double B[N][N];
double C[N][N];

int main(){
  for(int i=0; i < N; i++){
    for(int j=0; j < N; j++){
      for(int k=0; k < N; k++){
        C[i][j] += A[i][k] + B[k][j]; 
      }
    }
  }
  
  return 0;
}
