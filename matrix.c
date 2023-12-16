#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "display.h"
#include "mInverse.h"
#include "matrixDet.h"
#include "mAdjoint.h"
#include "mCofactor.h"
#include "mTranspose.h"


void readMatrix(int [][10], int);
void showMatrix(int [][10], int);
void showDet(int [][10], int, long);

int main() {
	int i,j,n;
	int ar[10][10];
	long det;

	struct mAdjoint a1;
	struct Cofactor c1;
	struct mTranspose t1;

	printf("Enter Matrix Order: ");
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("Enter El-[%d][%d]: ",(i+1),(j+1));
			scanf("%d", &ar[i][j]);
		}
	}

	printf("\n");
	showMatrixAdv(ar,n,"M");
	
	det = matrixDet(ar, n);
	printf("\n");
	showMatDet(ar, n, "DET", det);

	printf("\n");
	c1 = matrixCofact(ar, n);
	showMatrixAdv(c1.matrix, n, "CF");

	printf("\n");
	t1 = transpose(c1.matrix, n);
	showMatrixAdv(t1.tmat, n, "T");

	a1 = matAdjoint(ar, n);
	printf("\n");
	showMatrixAdv(a1.adMat, n, "Adj");

	printf("\n");
	matInverse(ar, n);

	//readMatrix(ar, n);
	//showMatrix(ar,n);
	//showDet(ar, n, det);

	return 0;
}

void readMatrix(int mat[][10], int n) {
	int i,j;
	
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			mat[i][j] = rand() % 1000 + 1;
		}
	}
}

void showMatrix(int ar[][10], int n) {
        int i,j;
	printf("\n\t*****Your Matrix*******\n");
        for(i=0; i<n; i++) {
                printf("|");
                for(j=0; j<n; j++) {
                        printf("%d ",ar[i][j]);
                }
                printf("\b|\n");
        }
}

void showDet(int ar[][10], int n, long det) {
	int i,j;
	printf("\n\t**********************\n");
	for(i=0; i<n; i++) {
		printf("|");
		for(j=0; j<n; j++) {
			printf("%d ",ar[i][j]);
		}
		printf("\b|");

		if(i == n/2) printf("\t\t%d\n", det);
		else printf("\n");
	}
}
