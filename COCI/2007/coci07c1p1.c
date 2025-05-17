/*
COCI '07 Contest 1 #1 Cetvrta
Author: Dan Shan
Date: 2025-02-22
set x and y cord to the respective cords with frequency = 1
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int a[2][3];
    for(int i=0;i<3;i++) scanf("%d %d",&a[0][i],&a[1][i]);
    int c=a[0][0],c2=a[1][0];
    if(c==a[0][1]) c=a[0][2];
    else if(c==a[0][2]) c=a[0][1]; 
    if(c2==a[1][1]) c2=a[1][2];
    else if(c2==a[1][2]) c2=a[1][1];
    printf("%d %d\n",c,c2);
}
