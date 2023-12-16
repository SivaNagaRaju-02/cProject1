#include <stdio.h>

#include "mInverse.h"
#include "mAdjoint.h"
#include "matrixDet.h"
#include "display.h"

void matInverse(int mat[][10], int n) {
    int i,j;
    long det;
    double val;
    double inv[10][10];
    struct mAdjoint a1;

    det = matrixDet(mat, n);
    if(det == 0) printf("Det = 0! Inverse Doesn't Exist...!");
    else {
        a1 = matAdjoint(mat, n);
        val = (double)1/det;

        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                inv[i][j] = val * a1.adMat[i][j];
            }
        }
    }

    dMatrix(inv, n, "INV");
}