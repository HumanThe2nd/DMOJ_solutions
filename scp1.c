// Singularity Cup P1 - Maximum Permutation Product
// By: Dan Shan
// Brute force small cases for edge cases and for large cases only prune the edges of 1 is there else return full array
include <stdio.h>
int main() {
int n,l=1,r=1;
double m = 0;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
if(n<16){
for(int i=0;i<n;i++){ // upper bound
	for(int k=0;k<=i;k++){ // lower bound
	double p = arr[k]; //
	for(int j=k+1;j<=i;j++){ // find permutation between bounds
		p*=arr[j];
	}
	p/=(i-k+1);
	// printf("%lf %d %d\n",p,k,i);
	if(p>m){m=p;l=k;r=i;}
	}
}
l++;r++;
// printf("%lf %d %d\n",m,l,r);
printf("%d %d\n",l,r);
}
else{
    if(arr[0]==1)printf("2 %d\n",n);
    else if(arr[n-1]==1)printf("1 %d\n",n-1);
    else printf("1 %d\n",n);
}
}
