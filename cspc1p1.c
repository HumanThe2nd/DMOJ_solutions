/*
CSPC '15 #1 - The Card Game
Author Dan Shan
Date: 2025-06-18
1. Remove invalid players
2. Output and remove restrictions if valid
3. Output respective results for numebr of remaining players
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n,c=0,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int ai;
        scanf("%d",&ai);
        if(ai<0) ++s;
        else c+=ai<14;
    } n-=s;
    if(c>1) printf("%d people are too young to play.\n",c);
    else if(c) printf("%d person is too young to play.\n",c);
    if(n-c==12) puts("Time to play!");
    else if(n-c<12) puts("There are not enough people to play.");
    else puts("There are too many people who want to play.");
}
