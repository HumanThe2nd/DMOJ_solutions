// COCI '17 Contest 2 #1 Košnja
// Author: Dan Shan
// formula: t = 2(min(n,m)-1)
#include <stdio.h>
int main() {
    int k;
	scanf("%d",&k);
	while(k--){
		int n,m;
		scanf("%d %d",&n,&m);
		if(n>m)n=m;
		printf("%d\n",2*(n-1));
	}
}
