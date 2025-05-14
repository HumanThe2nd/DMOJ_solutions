/*
DMOPC '15 Contest 2 P2 - Admin War
Author: HumanThe2nd
Date: 2025-04-15
2 counters 
*/
#include <stdio.h>
int main() {
    int n,f=0,x=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) {
        int ai;
        scanf("%d",&ai);
        if(ai==a[i]) continue;
        if(ai>a[i]) x++;
        else f++;
    }
    printf("%d %d\n",f,x);
    if(f==x) puts("Tie");
    else if(f<x) puts("FatalEagle");
    else puts("Xyene");
}
