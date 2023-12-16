#include <stdio.h>
#include <string.h>
#include "display.h"

int intLen(int x);
int dbLen(double x);

void showMatrixAdv(int m[][10], int n, char z[20]) {
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
			
			printf("\b|\n");
		}
	}
}

void dMatrix(double m[][10], int n, char z[20]) {
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
				len = dbLen(m[j][i]);
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
				len = dbLen(m[i][j]);
				if(len < clen[c]) {
					for(p=len; p<clen[c]; p++) printf(" ");
					printf("%0.4lf ",m[i][j]);
				}else {
					printf("%0.4lf ",m[i][j]);
				}
				c++;
			}
			
			printf("\b|\n");
		}
	}
}

int intLen(int x) {
	int n,len=0;
	
	if(x == 0) {
		return 1;
	}

	if(x < 0) {
		len++;
		n = x;
		while(1) {
			if(n == 0) break;
			len++;
			n = n/10;
		}
	}else {
		for(n=x; n>0; n = n/10) {
			len++;
		}
	}
	
	return len;
}

int dbLen(double x) {
	int n, len;

	n = (int) x;
	len = intLen(n);

	if(x < 0) {
		return len+6;
	}else {
		return len+5;
	}
}