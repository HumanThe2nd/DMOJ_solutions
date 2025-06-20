// DMOPC '18 Contest 5 P3 - A Familiar Problem
// By: Dan Shan
#include <stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
int main() {
    int n,l=0,mx=0;
    long long m;
    scanf("%d %lld",&n,&m);
    long long psa[n+1];
    psa[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&psa[i]);
        psa[i]+=psa[i-1];
    }
    for(int r=1;r<=n;r++){
        while(psa[r]-psa[l]>=m && l<r) l++;
        mx = MAX(mx,r-l);
    }
    printf("%d\n",mx);
}
