/*
DWITE '11 R1 #4 - C001 Numbers
Author: Dan Shan
Date: 2025-09-06

Brute force all number up to N
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    for(int ti=5;ti--;){
        int n,c=1;
        scanf("%d",&n);
        for(int i=10;i<=n;++i){
            int ai = i;
            while(ai){
                if(ai%10==0) ++c;
                ai/=10;
            }
        }
        printf("%d\n",c);
    }
}
