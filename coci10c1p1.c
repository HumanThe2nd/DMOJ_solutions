/*
COCI '10 Contest 1 #1 Timsko
Author: Dan Shan
Date: 2024-11-27
Brute force
*/
#include <stdio.h>
int main() {
    int g,b,k;
    scanf("%d %d %d",&g,&b,&k);
    k-=(g&1);
    g>>=1;
    while(k>0){
        if(g>b){
            g--;
            k-=2;
        }
        else{
            b--;
            k--;
        }
    }
    printf("%d\n",b<g?b:g);
}
