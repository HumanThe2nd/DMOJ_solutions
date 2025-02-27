/*
Author: Dan Shan
Date: 2024-12-30
we start at 1 and increment by 1 for each unhappy alpaca needed
when unhappy is finished the rest can be equal to the previous
impossible cases occur when unhappy alpacas are odd
*/
#include <stdio.h>
int main() {
    int n,x;
	scanf("%d %d",&n,&x);
	x=n-x; // use x to represent unhappy
	if(x&1) return puts("-1")*0; 
    int l=1;
    putchar('1');
    for(int i=0;i<n-1;i++){
        if(x){ // increase if more unhappy needed
            l++;
            x--;
        }
        printf(" %d",l);
    } putchar('\n');
}
