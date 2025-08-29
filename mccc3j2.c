/*
Mock CCC '22 Contest 1 J2 - Biking and Hiking
Author: Dan Shan
Date: 2025-08-28
- Update speed K
- prevent negatives
- count intervals of 0s
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n,k,c=0;
    char s[10002];
    scanf("%d %d %s",&n,&k,s);
    for(int i=0;i<n;++i){
        if(s[i]=='U') --k;
        else if(s[i]=='D') ++k;
        if(k<0) ++k;
        if(k<1) ++c;
    }
    printf("%d\n",c);
}
