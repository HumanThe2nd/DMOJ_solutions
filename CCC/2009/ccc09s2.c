/*
CCC '09 S2 - Lights Going On and Off
Author: Dan Shan
Date: 2025-02-18
store combinations as integers in binary
given the original bottom integer, we can xor 0 to R rows above it
we compute all distinct values of this chain
Time Complexity: O(RL)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int v[256];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n],c=0;
    for(int i=0;i<n;i++){
        a[i]=0;
        for(int j=0;j<m;j++){
            int ai;
            scanf("%d",&ai);
            a[i]<<=1;
            a[i]+=ai;
        }
    } v[a[n-1]]=1;
    for(int i=n-2;i>=0;i--){
        a[i]^=a[i+1];
        v[a[i]]++;
    }
    for(int i=0;i<256;i++) if(v[i]) c++;
    printf("%d\n",c);
}
