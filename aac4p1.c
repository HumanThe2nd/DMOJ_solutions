/*
An Animal Contest 4 P1 - Dasher's Digits
Author: Dan Shan
Date: 2024-12-05
last occurence of the largest cheer value acts as pivot for string shift
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int main() {
	int n=scan(),m=scan();
    char s[n];
    int a[m],r=0;
    for(int i=0;i<n;i++) {
        s[i]=getchar_unlocked();
        if(s[i]!='0') continue;
        a[r]=i; r++;
    }
    int mx=0,ind;
    for(int i=0;i<m;i++){
        int ai=scan();
        if(ai<mx) continue;
        mx=ai; ind=i;
    }
    int p=a[ind];
    for(int i=p+1;i<n;i++) if(s[i]!='0') putchar_unlocked(s[i]);
    for(int i=0;i<p;i++) if(s[i]!='0') putchar_unlocked(s[i]);
    putchar_unlocked('\n');
}
