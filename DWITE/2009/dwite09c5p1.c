/*
DWITE '09 R5 #1 - ASCII bar graphs
Author: Dan Shan
Date: 2025-08-08
Casework negative and positives
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    for(int ti=0;ti<5;++ti){
        int n;
        scanf("%d",&n);
        char s[]="-----|-----";
        n+=5;
        if(n<5){
            for(int i=n;i<5;++i) s[i]='*';
        }
        else{
            for(int i=6;i<=n;++i) s[i]='*';
        }
        puts(s);
    }
}
