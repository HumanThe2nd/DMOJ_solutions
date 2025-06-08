/*
MCIPC Contest 1 P3 - Cypher
Author: Dan Shan
Date: 2025-06-07
Place each eleemnt at its respective index in answer string
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n,ai;
    scanf("%d",&n);
    char s[n+1],s2[n+1]; s2[n]='\0';
    for(int i=1;i<=n;++i){
        char si[2];
        scanf("%s",si);
        s[i]=si[0];
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&ai);
        s2[ai-1]=s[i];
    } 
    puts(s2);
}
