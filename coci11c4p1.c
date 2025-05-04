/*
COCI '11 Contest 4 #1 Kino
Author: HumanThe2nd
Date: 2025-05-04
Start with an n+1 cupholders, each couple removes one
if there's no couples, one won't be used
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")

int main(){
    int n;
    char s[51];
    scanf("%d %s",&n,s);
    int c=n+1;
    for(int i=0;i<n;i++){
        if(s[i]=='L') c--,i++;
    }
    printf("%d\n",c<n?c:n);
}
