/*
COCI '10 Contest 7 #3 Gitara
Author: Dan Shan
Date: 2025-08-18
1. Create array to store frets at each string
2. For each note:
    - Release all greater notes on the string (1 move each)
    - If current note isn't pressed, press it (1 move)
3. Return total moves

Time Compleity: O(N)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<23 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
int a[7][500001],r[7];
int main(){
    buff();
    int n=scan(),p=scan(),c=0;
    while(n--){
        int ai=scan(), bi=scan();
        while(r[ai] && a[ai][r[ai]-1]>bi) --r[ai],++c; // release greater
        if(r[ai] && a[ai][r[ai] - 1] == bi) continue;
        ++c; a[ai][r[ai]++]=bi; // add current
    }
    printf("%d\n",c);
}
