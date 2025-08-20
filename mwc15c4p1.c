/*
MWC '15 #4 P1: Love Guru 2
Author: Dan Shan
Date: 2025-08-20
Solve for a,b,c and add 10 to each
Note: This problem's statement is very misleading
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int max(int a,int b){
    return a>b?a:b;
}
int main() {
    int ab,bc,ac;
    scanf("%d %d %d",&ab,&bc,&ac);
    int a=(ab+ac-bc)>>1,b=(ab+bc-ac)>>1,c=(ac+bc-ab)>>1;
    printf("%d\n%d\n%d\n",a+10,b+10,c+10);
}
