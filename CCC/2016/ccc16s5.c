/*
CCC '16 S5 - Circle of Life
Author: Dan Shan
Date; 2025-02-03
Brute force: xor every left and right index t times
Simplification:
split into exponents of 2 denoted by 'p'
xor each element with its 'p'th left and right index for every exponent
Time complexity O(N*log(T))
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    long long n,t,p=0;
    scanf("%lld %lld ",&n,&t);
    int a[2][n],r=0;
    for(int i=0;i<n;i++) a[0][i]=(getchar()-'0');
    while(t){
        while((t&1)==0&&t){ // for every power of 2 starting at 1 xor the respective index
            t>>=1;
            if(!p) p=1;
            else p<<=1;
        } 
        t>>=1;
        if(!p) p=1;
        else p<<=1;
        for(int i=0;i<n;i++){
            a[(r+1)%2][i]=(a[r][((i-p)%n+n)%n]^a[r][(i+p)%n]);
        } r++; r%=2;
    }
    for(int i=0;i<n;i++) putchar(a[r][i]+'0');
    putchar('\n');
}
