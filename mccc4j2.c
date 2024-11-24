/*
Mock CCC '22 Contest 2 J2 - Snowboarding Championship
Author: Dan Shan
Date: 2024-11-24
*/
#include <stdio.h>
int main() {
    int n,a,b,c=0,c2=0;
    scanf("%d %d %d",&n,&a,&b);
    while(n--){
        int h,h2;
        scanf("%d %d",&h,&h2);
        if(h<a) c++;
        else c+=2;
        if(h2<b) c2++;
        else c2+=2;
    }
    if(c<c2) printf("Andrew wins!\n");
    else if(c==c2) printf("Tie!\n");
    else printf("Tommy wins!\n");
}
