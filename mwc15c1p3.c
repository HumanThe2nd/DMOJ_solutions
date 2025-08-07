/*
MWC '15 #1 P3: Dolls
Author: Dan Shan
Date: 2025-08-06
Return absolute difference of (first_lowest_freq - last_highest_freq)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int v[101];
int main() {
    int n,l=2e9,r=0,li=0,ri=0;
    scanf("%d",&n);
    while(n--){
        int ai;
        scanf("%d",&ai);
        ++v[ai];
    }
    for(int i=1;i<101;++i){
        if(!v[i]) continue;
        if(v[i]<l) l=v[i],li=i;
        if(v[i]>=r) r=v[i],ri=i;
    }
    if(ri>li) printf("%d\n",ri-li);
    else printf("%d\n",li-ri);
}
