// The Cake is a Dessert
// Author: Dan Shan
// Date: 2024-09-27
// 2d psa template
#include <stdio.h>
int main() {
	long long n,m,k,q;
	scanf("%lld %lld %lld",&n,&m,&k);
	long long a[n+2][m+2];
	for(int i=0;i<n+2;i++){
		for(int j=0;j<m+2;j++) a[i][j]=0;
	}
	while(k--){
		long long xi,yi,xf,yf;
		scanf("%lld %lld %lld %lld",&xi,&yi,&xf,&yf);
		a[xi][yi]++; a[xf+1][yf+1]++;
		a[xf+1][yi]--; a[xi][yf+1]--;
	}
	scanf("%lld",&q);
	for(int i=1;i<n+2;i++){
		for(int j=1;j<m+2;j++){
			a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
		}
	}
	for(int i=1;i<n+2;i++){
		for(int j=1;j<m+2;j++){
			a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
		}
	}
	while(q--){
		long long xi,yi,xf,yf;
		scanf("%lld %lld %lld %lld",&xi,&yi,&xf,&yf);
		printf("%lld\n",a[xf][yf]-a[xi-1][yf]-a[xf][yi-1]+a[xi-1][yi-1]);
	}
}
