// Educational DP Contest AtCoder D - Knapsack 1
// By: Dan Shan
#include<stdio.h>
long long max(long long a,long long b){return a>b?a:b;}
int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	int val[n],wt[n];
	long long k[n+1][w+1];
	for(int i=0;i<n;i++)
		scanf("%d %d",&wt[i],&val[i]);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(!i||!j) k[i][j]=0;
			else if(wt[i-1]<=j)
				k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
			else k[i][j]= k[i-1][j];
		}
	}
	printf("%lld\n",k[n][w]);
}
