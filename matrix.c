#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "display.h"
#include "mInverse.h"
#include "matrixDet.h"
#include "mAdjoint.h"
#include "mCofactor.h"
#include "mTranspose.h"
#include "subMatrix.h"

void manualRead(int [][10], int);
void readRandom(int [][10], int);
void showMatrix(int [][10], int);
void showDet(int [][10], int, long);

int main() {
	int opt1 = -1, opt2, opt, n, p1, p2;
	int mat[10][10];
	long det;

	struct matrices s1;
	struct mAdjoint a1;
	struct Cofactor c1;
	struct mTranspose t1;

	while(opt2 != 0) {
		printf("Enter Matrix Order: ");
		scanf("%d", &n);
		printf("\t[1]. Manual Read Matrix.\n");
		printf("\t[2]. Auto Read Matrix.\n");
		printf("Choose an Opt: ");
		scanf("%d", &opt);

		switch(opt) {
			case 1: manualRead(mat, n);
				break;
			case 2: readRandom(mat, n);
				break;
			default : printf("Choose a Valid Option..! Invalid Key Error.");
				continue;
		}

		showMatrixAdv(mat, n, "Mat");

		opt2 = -1;
		while(opt2 != 9 && opt2 != 0) {
			printf("\n\t\t*****MENU*****\n");
			printf("\t[1]. Display Matrix.\n");
			printf("\t[2]. Det of Matrix.\n");
			printf("\t[3]. SubMatrix.\n");
			printf("\t[4]. Cofactor of Matrix.\n");
			printf("\t[5]. Transpose of Matrix.\n");
			printf("\t[6]. Adjoint of Matrix.\n");
			printf("\t[7]. Inverse of Matrix.\n");
			printf("\t[9]. To Update Matrix.");
			printf("\t[0]. To Exit.\n");

			printf("Choose an Option: ");
			scanf("%d", &opt2);

			printf("\n");
			switch(opt2) {
				case 1: showMatrixAdv(mat,n,"M");
					break;
				case 2: det = matrixDet(mat, n);
					showMatDet(mat, n, "DET", det);
					break;
				case 3:
					printf("Enter a Position to Produce a Minor: ");
					scanf("%d %d",&p1, &p2);
					s1 = subMatrix(mat, n, p1, p2);
					showMatrixAdv(s1.subMat, n-1, "S");
					break;
				case 4: c1 = matrixCofact(mat, n);
					showMatrixAdv(c1.matrix, n, "CF");
					break;
				case 5: t1 = transpose(mat, n);
					showMatrixAdv(t1.tmat, n, "T");
					break;
				case 6: a1 = matAdjoint(mat, n);
					showMatrixAdv(a1.adMat, n, "Adj");
					break;
				case 7: matInverse(mat, n);
					printf("This is the End of the session...! Please read a new Matrix.\n");
					opt2 = 9;
					break;
				case 9: printf("You Choose to update the Matrix..!\n");
					break;
				case 0: printf("You choose to Exit..!\n");
					break;
				default : printf("You enterd an Invalid Option..! Please choose again.\n");
					opt = 9;
			}
		}
	}

	return 0;
}

void readRandom(int mat[][10], int n) {
	int i,j;
	
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			mat[i][j] = rand() % 1000 + 1;
		}
	}
}

void manualRead(int mat[][10], int n) {
	int i,j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("Enter El-[%d][%d]: ",(i+1),(j+1));
			scanf("%d", &mat[i][j]);
		}
	}
}

void showMatrix(int mat[][10], int n) {
        int i,j;
	printf("\n\t*****Your Matrix*******\n");
        for(i=0; i<n; i++) {
                printf("|");
                for(j=0; j<n; j++) {
                        printf("%d ",mat[i][j]);
                }
                printf("\b|\n");
        }
}

void showDet(int mat[][10], int n, long det) {
	int i,j;
	printf("\n\t**********************\n");
	for(i=0; i<n; i++) {
		printf("|");
		for(j=0; j<n; j++) {
			printf("%d ",mat[i][j]);
		}
		printf("\b|");

		if(i == n/2) printf("\t\t%d\n", det);
		else printf("\n");
	}
}
