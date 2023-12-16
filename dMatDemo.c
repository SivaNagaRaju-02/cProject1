#include <stdio.h>
#include "display.h"

void main() {
    int i,j,n;
	double mat[10][10];

	printf("Enter Matrix Order: ");
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("Enter El-[%d][%d]: ",(i+1),(j+1));
			scanf("%lf", &mat[i][j]);
		}
	}

    dMatrix(mat, n, "DMAT");
}