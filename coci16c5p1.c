/*
COCI '16 Contest 5 #1 Tuna
Author: Dan Shan
Date: 2025-08-15

For each fish:
1. input 2 values, (set second as max for simplicity)
2. if difference > x, input another value to add
   else add the larger value
3. Return total sum
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n,x,c=0;
    scanf("%d %d",&n,&x);
    while(n--){
        int ai,bi,xi;
        scanf("%d %d",&ai,&bi);
        if(ai>bi){
            int temp=ai;
            ai=bi; bi=temp;
        }
        if(bi-ai<=x){
            c+=bi; continue;
        }
        scanf("%d",&xi);
        c+=xi;
    }
    printf("%d\n",c);
}
