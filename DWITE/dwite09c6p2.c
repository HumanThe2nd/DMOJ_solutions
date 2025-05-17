/*
DWITE '09 R6 #2 - Round to power of two
Author: HumanThe2nd
Date: 2025-03-20
store powers of 2 and find value with minimum difference
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int abs(int a){
    return a<0?-a:a;
}
int main() {
    int a[17]; a[0]=1;
    for(int i=1;i<17;i++){
        a[i]=a[i-1]*2;
    }
    for(int i=0;i<5;i++){
        int n,d=2e9,ind=1;
        scanf("%d",&n);
        for(int j=0;j<17;j++){
            if(abs(n-a[j])<=d){
                d=abs(n-a[j]); ind=a[j];
            }
        }
        printf("%d\n",ind);
    }
}
