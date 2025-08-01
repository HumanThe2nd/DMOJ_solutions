/*
DMOPC '20 Contest 3 P1 - Present Checking
Author: Dan Shan
Date: 2025-08-01
1. Create visited array of each friend (up to 1e6+1)
2. If any friend is visited twice, it's invalid\

TC: O(N)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<25 // Templates
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
int v[1000001];
int main(){
    buff();
    int n=scan();
    while(n--){
        int li=scan();
        if(v[li]) return !puts("NO");
        v[li]=1;
    } puts("YES");
}
