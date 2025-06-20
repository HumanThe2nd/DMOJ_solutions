/*
DMOPC '19 Contest 4 P0 - Yikes
Author: Dan Shan
Date: 2025-05-15
Count unmatched characters
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    char a[1001],b[1001];
    int c=0;
    scanf("%s %s",a,b);
    for(int i=0;i<1001;i++){
        if(a[i]=='\0') break;
        if(a[i]!=b[i]) c++;
    }
    if(c==1) puts("LARRY IS SAVED!");
    else puts("LARRY IS DEAD!");
}
