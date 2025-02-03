/*
Baltic OI '03 P5 - Lamps
Author: Dan Shan
Date: 2025-02-02
split time m into powers of 2 starting from 1 denoted by 'p'
for every exponent 'p', xor every lamp with the 'p'th next lamp
compress the different states to save memory (rte otherwise)
Time complexity: O(N*logM)
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // buffer size
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // fast input template
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int cmp(const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}
int main(){
    buff();
    int n=scan(),k=scan(),p=0;
    int a[2][n],r=0; // compress to 2 states
    for(int i=0;i<n;i++) a[0][i]=scan();
    while(k){
        while((k&1)==0&&k){ // for every power of 2 starting at 1 xor the respective index
            k>>=1;
            if(!p) p=1;
            else p<<=1;
        } 
        k>>=1;
        if(!p) p=1;
        else p<<=1;
        for(int i=0;i<n;i++){
            a[(r+1)%2][i]=(a[r][i]^a[r][(i+p)%n]);
        } r++; r%=2;
    }
    for(int i=0;i<n;i++) printf("%d\n",a[r][i]);
}
