/*
COCI '08 Contest 3 #1 Pet
Author: Dan Shan
Date: 2025-09-02

Find max sum of grades
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int w,m=0;
    for(int i=1;i<6;++i){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        a+=b+c+d;
        if(a>m) m=a,w=i;
    }
    printf("%d %d\n",w,m);
}
