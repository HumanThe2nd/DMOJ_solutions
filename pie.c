/*
Pie
Author: Dan Shan
Date: 2025-08-17
1. Each person has nothing, pie = 1.0
2. For each operation give pi*pie/100 too person ai and subtract it from the pie
3. Outout each person's receieved pie
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    double a[n+1],p=1;
    for(int i=1;i<=n;++i) a[i]=0;
    while(m--){
        int ai,pi;
        scanf("%d %d",&ai,&pi);
        a[ai]+=(double)pi*p/100;
        p-=(double)pi*p/100;
    }
    for(int i=1;i<=n;++i) printf("%lf\n",a[i]);
}
