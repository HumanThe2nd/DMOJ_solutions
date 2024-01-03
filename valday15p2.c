// Valentine's Day '15 P2 - Simon and Marcy
// By: Dan Shan
// template knapsack dp implementation
#include<stdio.h>
int max(int a,int b){return(a>b)?a:b;}
int main() {
	int c,m; // m: max weight
	scanf("%d %d",&c,&m);
    int val[c], wt[c];
    for(int i=0;i<c;i++){
    	scanf("%d %d",&val[i],&wt[i]);
    }
    int n = sizeof(val)/sizeof(val[0]);
    int i, w;
    int K[n+1][m+1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= m; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            else
                  K[i][w] = K[i-1][w];
        }
    }
    printf("%d\n", K[n][m]);
}
