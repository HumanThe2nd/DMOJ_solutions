// DMOPC '17 Contest 2 P1 - 0-1 Knapsack
// By: Dan Shan
// note: long integer needed
#include<stdio.h>
int main() {
	int n;
	long long int ct=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int c,v;
		scanf("%d %d",&c,&v);
		if(v>0)ct+=c;
	}
	printf("%lld\n",ct);
}
