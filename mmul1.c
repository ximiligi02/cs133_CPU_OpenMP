#include "const.h"

void mmul1(float A[ni][nk], float B[nk][nj], float C[ni][nj])
{
	int i, j, k;
  float temp;
  #pragma omp parallel for private(j)
	for (i=0; i<ni; i++) {
		for (j=0; j<nj; j++) {
			C[i][j] = 0;
      }
      }
  #pragma omp parallel for private(k,j,temp)   
   for (i=0; i<ni; i++) {
			for (k=0; k<nk; k++) {
        temp=A[i][k];
        for (j=0; j<nj; j++) {
				C[i][j] += temp*B[k][j];
			}
		}
   }
	}


