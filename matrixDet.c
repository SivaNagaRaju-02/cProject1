#include <stdio.h>
#include <string.h>
#include "matrixDet.h"
#include "display.h"
#include "subMatrix.h"

long matrixDet(int mat[][10], int n) {
	int i,j;
	struct matrices m1;
	long det = 0;

	if(n == 0) {
		printf("\nDet Doesn't exist\n");
		det = -99999;
	}else if(n == 1) {
		det = mat[0][0];
	}else{
		for(i=0; i<n; i++) {
			m1 = subMatrix(mat, n, 0, i);
			if(i%2 == 0) {
				det = det + mat[0][i] * matrixDet(m1.subMat, n-1);
			}else{
				det = det - mat[0][i] * matrixDet(m1.subMat, n-1);
			} 
		}
	}
	return det;
}

void showMatDet(int m[][10], int n, char z[20], long det) {
	int i,j,k,l,p,q,r,c;
	int clen[10],rlen=0;
	int temp,len;
	if(r == 0) {
		printf("\t***----***\n");
		printf("\t   |NA|\n");
	}else{
		c = 0;

		for(i=0; i<n; i++) {
			clen[c] = 0;
			for(j=0; j<n; j++) {
				len = intLen(m[j][i]);
				if(clen[c] < len) clen[c] = len;
			}
			rlen += clen[c];
			c++;
		}

		q = strlen(z);
		l = rlen+n-1;
		if(l < 9+q) {
			printf("\t****-");
			for(i=0; i<rlen+n-1; i++) {
				printf("-");
			}
			printf("-****\n");
		}else{
			if((l%2!=0 && q%2==0) | (l%2==0 && q%2!=0)) {
				temp = (9+q)/2;
			}else{
				temp = (8+q)/2;
			}

			printf("\t*****");
			for(i=0; i<l/2-temp-1; i++) {
				printf("*");
			}
			printf("|Matrix");
			if((l%2!=0 && q%2==0) | (l%2==0 && q%2!=0)){
				printf("-");
			}
			printf("[%s]|",z);
			for(i=0; i<l/2-temp-1; i++) {
				printf("*");
			}
			printf("*****\n");
		}

		for(i=0; i<n; i++) {
			printf("\t    |");
			c = 0;
			for(j=0; j<n; j++) {
				len = intLen(m[i][j]);
				if(len < clen[c]) {
					for(p=len; p<clen[c]; p++) printf(" ");
					printf("%d ",m[i][j]);
				}else {
					printf("%d ",m[i][j]);
				}
				c++;
			}
			
			if(i == n/2) {
				printf("\b|\t = %d\n",det);
			}else {
				printf("\b|\n");
			}
		}
	}
}
