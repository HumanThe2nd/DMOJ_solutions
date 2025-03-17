/*
CCC '25 J2 - Donut Shop
Author: HumanThe2nd
Date: 2025-03-16
Take the maximum between zero and the total sum of input
*/
#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        char s[3];
        int ai;
        scanf("%s %d",s,&ai);
        if(s[0]=='+') n+=ai;
        else n-=ai;
    }
    if(n>0) printf("%d\n",n);
    else puts("0");
}
