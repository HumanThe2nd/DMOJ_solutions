/*
DWITE '08 R2 #2 - My favourite digit
Author: Dan Shan
Date: 2025-06-29
Modular arithmetic
*/
#include <stdio.h>
int main() {
    for(int ti=0;ti<5;++ti){
        int ai,m=0;
        scanf("%d",&ai);
        while(ai){
            if(ai%10>m)m=ai%10;
            ai/=10;
        }
        printf("%d\n",m);
    }
}
