/*
COCI '12 Contest 3 #1 Sahovnica
Author: Dan Shan
Date: 2025-05-05
Implmentation
Approach: the sum of i/a and j/b modulo 2 gives the character at cell [i][j]
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int r,c,a,b;
    scanf("%d %d %d %d",&r,&c,&a,&b);
    for(int i=0;i<r*a;i++){
        int ai=i/a;
        for(int j=0;j<c*b;j++){
            int bi=(j/b+ai)&1; // current cell value
            putchar(bi?'.':'X');
        }
        putchar('\n');
    }
}
