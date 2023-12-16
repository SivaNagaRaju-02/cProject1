#include "mAdjoint.h"
#include "mCofactor.h"
#include "mTranspose.h"

struct mAdjoint matAdjoint(int mat[][10], int n) {
    struct mAdjoint a1;
    struct Cofactor c1;
    struct mTranspose t1;

    int i,j;

    c1 = matrixCofact(mat, n);
    t1 = transpose(c1.matrix, n);

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            a1.adMat[i][j] = t1.tmat[i][j];
        }
    }
    
    return a1;
}