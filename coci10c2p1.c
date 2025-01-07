/*
COCI '10 Contest 2 #1 Puž
Author: Dan Shan
Date: 2025-01-06
x(a-b)+a >= v
x = ceil((v-a)/(a-b))
x = (floor(c-b-1)/(a-b)+1)
*/
#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",(c-b-1)/(a-b)+1);
}
