/*
DMOPC '14 Contest 7 P2 - Tides
Author: Dan Shan
Date: 2025-02-16
verify that max comes after min following a series of increments
if valid, output the difference between max and min
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n,min=2e9,max=0,i1,i2;
    scanf("%d",&n);
    int a[n],f=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<min) min=a[i],i1=i;
        if(a[i]>max) max=a[i],i2=i;
    }
    if(i1>=i2) return puts("unknown")*0;
    for(int i=i1+1;i<=i2;i++) if(a[i-1]>=a[i]) return puts("unknown")*0;
    printf("%d\n",max-min);
}
