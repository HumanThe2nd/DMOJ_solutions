// Appleby Contest '19 P1 - Darcy's Debilitating Demands
// By: Dan Shan
// queue/array structure
// Note usage of long long for comparision to prevent overflow
#include<stdio.h>
#define min(a,b)((a)<(b)?(a):(b))
int main() {
	int t;
    scanf("%d",&t);
    while(t--){
        int n,a,b,c;
        scanf("%d %d %d %d",&n,&a,&b,&c);
        if((long long)a+b+c<(long long)n){
            printf("-1\n");
            continue;
        }
        int ci=min(n,c);
        n-=ci;
        int bi=min(n,b);
        n-=bi;
        int ai=min(n,a);
        printf("%d %d %d\n",ai,bi,ci);
    }
}
