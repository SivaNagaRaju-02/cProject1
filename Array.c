void showArray(int x[10], int n) {
	int i;
	printf("Array = [");
	for(i=0; i<n; i++) {
		if(i < n-1) printf("%d, ",x[i]);
		else printf("%d]\n",x[i]);
	}
}