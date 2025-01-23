/*
COCI '14 Contest 5 #1 Funghi
Author: Dan Shan
Date: 2025-01-22
Brute froce maximum 4 adjcent values
*/
#include <stdio.h>
int a[8];
int main(){
    for(int i=0;i<8;i++){
        scanf("%d",&a[i]);
    }
    int m=0;
    for(int i=0;i<8;i++){
        int ci=a[i]+a[(i+1)%8]+a[(i+2)%8]+a[(i+3)%8];
        if(ci>m) m=ci;
    }
    printf("%d\n",m);
}
