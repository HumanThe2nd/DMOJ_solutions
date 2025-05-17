/*
COCI '10 Contest 7 #1 Šećer
Author: Dan Shan
Date: 2025-02-07
mod 3 while not divisible by 5
if never divisible by 5, impossible
*/
#include <stdio.h>
int main() {
	int n,c=0;
    scanf("%d",&n);
    while(n%5&&n>2){
        c++;
        n-=3;
    }
    c+=n/5;
    n%=5;
    if(n) puts("-1");
    else printf("%d\n",c);
}
