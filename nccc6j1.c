/*
Mock CCC '19 Contest 1 J1 - Pusheen's Report Card
Author: Dan Shan
Date: 2025-07-18
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b) printf("CS452\n");
    else if(b>a) printf("PHIL145\n");
}
