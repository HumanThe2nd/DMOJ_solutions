// Educational DP Contest AtCoder E - Knapsack 2
// By: Dan Shan
#include<stdio.h>
#define MM 100000 // maximum possible value
#define max(a,b)(a>b?a:b)
#define min(a,b)(a>b?b:a)
int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	int val[n+1],wt[n+1];
	for(int i=0;i<n;i++){
		scanf("%d %d",&wt[i],&val[i]);
	}
	long long int k[MM+1];
	for(int i=0;i<=MM;i++){
		k[i]=1e11+1; // pseudoinfinite
	}
	k[0]=0;
	for(int i=0;i<n;i++){
		for(int j=MM;j>=val[i];j--)
			k[j]=min(k[j],k[j-val[i]]+wt[i]);
	}
	int mv = 0;
	for(int i=0;i<=MM;i++)
		if(k[i]<=w) mv=i;
	printf("%d\n",mv);
}
