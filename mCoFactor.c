#include "mCofactor.h"
#include "subMatrix.h"
#include "matrixDet.h"

struct Cofactor matrixCofact(int mat[][10], int n) {
    int i,j;
    struct Cofactor c1;
    struct matrices m1;
    
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            m1 = subMatrix(mat, n, i, j);
            if((i+j)%2 == 0) c1.matrix[i][j] = matrixDet(m1.subMat, n-1);
            else c1.matrix[i][j] = -(matrixDet(m1.subMat, n-1));
        }
    }

    return c1;
}