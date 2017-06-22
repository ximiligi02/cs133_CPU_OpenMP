#include "const.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#define STEP 32


void mmul2(float A[ni][nk], float B[nk][nj], float C[ni][nj])
{
 
  int i, j, k, it, jt, kt;
  float temp;
  //int num;
  //int id;

  
  
   #pragma omp parallel for private(kt,jt,i,k,j,temp)
   
   //num=nk/omp_get_num_threads();
   //id=num*omp_get_thread_num();
   
   
  
   for (it=0; it<ni; it+=STEP){
    
     for (jt=0; jt<nj; jt+=STEP){ 
     float buffer[STEP][STEP];
     memset(buffer,0,sizeof(float)*STEP*STEP);
      for (kt=0; kt<nk; kt+=STEP){
      for (i=it; i<it+STEP; i++) {
			for (k=kt; k<kt+STEP; k++) {
        temp=A[i][k];
        for (j=jt; j<jt+STEP; j++) {
			   buffer[i-it][j-jt] += temp*B[k][j];
        
			}
		}
   }
   }
   for (i=0; i<STEP; i++)
   memcpy(&C[it+i][jt], &buffer[i][0], sizeof(float)*STEP);
   }
   }
   
 
   
   
}

