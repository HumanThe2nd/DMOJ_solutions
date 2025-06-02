/*
Cheerio Contest 1 J3 - Festival
Author: Dan Shan
Date: 2025-06-02
Count 'S' in each column
Put them at the bottom of each
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int a[1501];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char si[1501];
        scanf("%s",si);
        for(int j=0;j<n;++j) a[j]+=si[j]=='S';
    }
    for(int i=n;i>0;--i){
        char si[n+1];
        for(int j=0;j<n;++j){
            if(i<=a[j]) si[j]='S';
            else si[j]='.';
        }
        si[n]='\0';
        puts(si);
    }
}
