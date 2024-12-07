/*
Appleby Contest '20 P2 - Playful Playdoughs
Author: Dan Shan
Date: 2024-12-06
frequency counter
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
long long scan() {
    long long num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
void print(long long n) {
    if(!n) putchar_unlocked('0');
    char s[19];
    long long i=0;
    while(n>0){
        s[i++]=(n%10)+'0';
        n/=10;
    }
    while (--i >= 0) {
        putchar_unlocked(s[i]);
    }
    putchar_unlocked('\n');
}
long long a[100001];
int main() {
	long long n=scan(),q=scan();
    while(n--){
        long long ai=scan();
        a[ai]++;
    }
    while(q--){
        long long qi=scan(),ai=scan();
        if(qi==1){
            a[ai/2]+=a[ai];
            a[ai/2+(ai&1)]+=a[ai];
            a[ai]=0;
        }
        else print(a[ai]);
    }
}
