/*
Mock CCC '20 Contest 1 J1 - A Rage Tree Problem
Author: Dan Shan
Date: 2025-07-15
Min and Max
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int a=100,b=1;
    for(int i=0;i<4;++i){
        int ai;
        scanf("%d",&ai);
        if(ai<a) a=ai;
        if(ai>b) b=ai;
    }
    printf("%d\n%d\n",a,b);
}
