/*
DMOPC '16 Contest 2 P1 - Seed Strategy
Author: Dan Shan
Date: 2025-02-23
represent time in seconds to avoid decimals
if time used <= n, continue
otherwise return
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    n*=60;
    for(int i=0;i<k;i++){
        int ai;
        scanf("%d",&ai);
        if(ai==1) n-=30;
        else if(ai==2) n-=60;
        else n-=300;
    }
    puts(n>=0?"Continue":"Return");
}
