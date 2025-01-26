/*
DMOPC '14 Contest 2 P1 - Logging Log
Author: Dan Shan
Date: 2025-01-25
sum of list
*/
#include <stdio.h>
int main(){
    int d;
    scanf("%d",&d);
    for(int i=1;i<=d;i++){
        int ai,c=0;
        scanf("%d",&ai);
        while(ai--){
            int ti;
            scanf("%d",&ti);
            c+=ti;
        }
        if(c) printf("Day %d: %d\n",i,c);
        else puts("Weekend\n"); // seperate output when sum is zero
    }
}
