// DMOPC '23 Contest 1 P1 - Peak Grid
// By: Dan Shan
#include <stdio.h>
int main(){
int n,k;
scanf("%d %d",&n,&k);
if(k>n){
	printf("-1\n");
	return 0;
}
int a[n][n];
for(int i=0;i<n;i++){ // initialize as a sorted array
	for(int j=1;j<=n;j++){
		a[i][j-1]=i*n+j;
	}
} n--; // for 0 indexing
for(int i=1;i<k;i++){
	int t = a[n][n-i];
	a[n][n-i] = a[n-i][n-i];
	a[n-i][n-i] = t;
}
for(int i=0;i<=n;i++){
	for(int j=0;j<n;j++){
		printf("%d ",a[i][j]);
	}
	printf("%d\n",a[i][n]);
}
}
