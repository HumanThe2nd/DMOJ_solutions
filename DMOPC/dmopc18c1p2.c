/*
DMOPC '18 Contest 1 P2 - Sorting
Author: Dan Shan
Date: 2024-12-20
take absolute value of each value and find absolute difference with its index
if any difference is not divisible by k, it is impossible
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
int abs(int a){
    return a<0?-a:a;
}
int main() {
    int n=scan(),k=scan(),f=1;
    for(int i=1;i<=n;i++){
        int ai=scan();
        if((abs(ai)-i)%k!=0) f=0;
    }
    if(f) puts("YES\n");
    else puts("NO\n");
}
