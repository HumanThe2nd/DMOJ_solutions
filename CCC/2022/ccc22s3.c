/*
CCC '22 S3 - Good Samples
Author: Dan Shan
Date: 2024-10-17
start at 1
for each number additional number:
if extra filled add minimum of last digit
else if within bounds and less than m, at max
else if m is reached reset 
else fill the remaining that don't need to be used
*/
#include <stdio.h>
int main() {
	long long n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	if(k>(n*(n+1))/2||n>k) return printf("-1\n")*0; // impossible constraints
	int a[n]; a[0]=1;
	long long c=n;
	for(int i=1;i<n;i++){
		if(c==k) a[i]=a[i-1]; // min
		else if(i<m&&c+i<=k){ // max
			a[i]=i+1;
			c+=i;
		}
		else if(c+m<k+2){ // reset
			a[i]=a[i-m];
			c+=m-1;
		}
		else {
			a[i]=a[i-(k-c)-1]; // max-> min
			c=k;
		}
	}
	if(c!=k) return printf("-1\n")*0;
	for(int i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
}
