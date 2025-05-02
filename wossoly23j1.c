/*
WOSS Dual Olympiad 2023 J1: Minimum Price
Author: HumanThe2nd
Date: 2025-05-02
Minimum
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24
char buf[bs]; // Templates
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0;
    int neg=0;
    while (*ptr!='-'&&(*ptr<'0'||*ptr>'9')) ++ptr; // Skip non-digit/non-negative characters
    if (*ptr=='-') {
        neg=1;
        ++ptr;
    }
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return neg?-num:num;
}
int main() {
    buff();
    int n=scan(),m=scan();
    while(--n){
        int ai=scan();
        if(ai<m)m=ai;
    }
    printf("%d\n",m);
}
