/*
COCI '07 Contest 5 #2 Pascal
Author: HumanThe2nd
Date: 2025-03-14
Find number of decrements from n until its divisible
Observation: It will always be N - LF
where LF is the largest factor of N excluding itself (unless n=1)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return printf("%d\n",n-n/i)*0;
    }
    printf("%d\n",n-1); // no factors except itself and 1
}
