/*
CCC '25 J4 - Sunny Days
Author: HumanThe2nd
Date: 2025-03-28
store size of each 'S' group in relative order (including 0)
if only 1 group exists: print n-1 to subtract from an edge
otherwise: find minimum of 2 adjacent groups
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    scanf("%d",&n);
    int q[n],r=0,li=-1;
    for(int i=0;i<n;i++){
        char s[2];
        scanf("%s",s);
        if(s[0]=='P'){
            q[r++]=i-li-1;
            li=i;
        }
    }
    q[r++]=n-li-1;
    int mx=0;
    for(int i=1;i<r;i++) if(q[i]+q[i-1]>mx) mx=q[i]+q[i-1];
    if(r==1) printf("%d\n",n-1);
    else printf("%d\n",mx+1);
}
