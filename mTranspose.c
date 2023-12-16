#include "mTranspose.h"

struct mTranspose transpose(int m[][10], int n) {
    int i,j;
    struct mTranspose t1;

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            t1.tmat[i][j] = m[j][i];
        }
    }

    return t1;
}