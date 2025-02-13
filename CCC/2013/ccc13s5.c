/*
CCC '13 S5 - Factor Solitaire
Author: Dan Shan
Date: 2025-01-12

Approach:
find the largest factor of n inequal to itself
subtract the factor from n
add the quotient of n and that factor to the cost
repeat until the current number is 1
it can be proven this is optimal as you are minimizing the difference between each pair of cards
*/
#include <stdio.h>
int main(){
    int n,c=0;
    scanf("%d",&n);
    while(n>1){
        int f; // smallest factor over 1
        for(f=2;f*f<=n;f++){
            if(!(n%f)) break;
        }
        if(n%f) f=n; // prime number
        int lf=n/f; // largest factor
        n-=lf;
        c+=n/lf;
    }
    printf("%d\n",c);
}
