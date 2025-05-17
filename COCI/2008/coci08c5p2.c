/*
COCI '08 Contest 5 #2 Jabuka
Author: HumanThe2nd
Date: 2025-04-16
store all factors of R
check whether G can divide each factor
Time complexity: O( sqrt(R) )
*/
#include <stdio.h>
int main() {
    int r,g;
    scanf("%d %d",&r,&g);
    int q[100001],l=0;
    for(int i=1;i*i<=r;i++){
        if(r%i) continue; // not divisible
        q[l++]=i;
        if(r/i!=i) q[l++]=r/i;
    }
    for(int i=0;i<l;i++){
        int ai=q[i];
        if(g%ai) continue; // not divisible
        printf("%d %d %d\n",ai,r/ai,g/ai);
    }
}
