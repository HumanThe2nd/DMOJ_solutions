/*
Arcadia Computing Contest 1 P3 - ScanTron
Author: Dan Shan
Date: 2024-12-01
Prefix sum array + suffix sum array
*/
#include <stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int p[1000001],p2[1000001];
int main() {
	int n;
	scanf("%d\n",&n);
	char s[n+1],s2[n];
	for(int i=0;i<=n;i++) s[i]=getchar_unlocked();
	int m=0;
	for(int i=1;i<n;i++){
		s2[i]=getchar_unlocked();
		p[i]=p[i-1];
		if(s2[i]==s[i-1]) p[i]++;
	}
	for(int i=n;i-->0;){
		p2[i]=p2[i+1];
		if(s2[i]==s[i]) p2[i]++;
		m = max(m,p[i-1]+p2[i]);
	}
	printf("%d\n",m);
}
