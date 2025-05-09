/*
GFSSOC '15 Fall J1 - CodeFights
Author: Dan Shan
Date: 2025-05-09
absolute difference
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<20 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int main(){
    buff();
    int a=scan(),n=scan();
    while(n--){
        int ai=scan();
        if(ai-a>100||a-ai>100) puts("go away! 3:<");
        else  puts("fite me! >:3");
    }
}
