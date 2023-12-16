#include "subMatrix.h"
//#include "display.h"

struct matrices subMatrix(int mat[][10], int n, int p, int q) {
	int i,j,r,c;
	struct matrices m1;
	r = 0;
	for(i=0; i<n; i++) {
		if(i != p) {
            c = 0;
            for(j=0; j<n; j++) {
                if(j != q) {
                    m1.subMat[r][c] = mat[i][j];
                    c++;
                }
            }
            r++;
        }
	}

    //showMatrixAdv(m1.subMat, n-1, "SMAT");
	return m1;
}