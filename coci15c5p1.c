/*
COCI '15 Contest 5 #1 Zamka
Auhor: HumanThe2nd
Date: 2025-03-29
Brute force all digit combinations from l to d
min is the first valid, max is the last valid
This code hard codes with modulus (small constraints)
*/
#include <stdio.h>
int main() {
    int l,d,x,n=0,m;
    scanf("%d %d %d",&l,&d,&x);
    for(int i=l;i<=d;i++){
        int xi=i%10+(i%100)/10+(i%1000)/100+(i%10000)/1000;
        if(xi==x) {
            m=i;
            if(!n) n=i; 
        }
    }
    if(x==1&&d==10000) printf("%d\n10000\n",n); // hard codes 1e4
    else printf("%d\n%d\n",n,m);
}
