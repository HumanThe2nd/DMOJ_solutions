/*
COCI '10 Contest 6 #1 Okulpjanje
Author: Dan Shan
Date: 2025-02-03
find difference of each article from the product of people and area
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    a*=b;
    for(int i=0;i<5;i++){
        int ai;
        scanf("%d",&ai);
        printf("%d",ai-a);
        putchar(i==4?'\n':' ');
    }
}
