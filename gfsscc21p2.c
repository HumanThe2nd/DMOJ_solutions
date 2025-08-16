/*
GFSS Christmas Challenge P2 - Height Inspection
Author: Dan Shan
Date: 2025-08-16

Track max and min
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n,l;
    scanf("%d %d",&n,&l);
    int r=l;
    while(--n){
        int ai;
        scanf("%d",&ai);
        if(ai>r) r=ai;
        if(ai<l) l=ai;
    }
    printf("%d\n%d\n",l,r);
}
