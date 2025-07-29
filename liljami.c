/*
Lil' Jami
Author: Dan Shan
Date: 2025-07-28
Prefix Sum array
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int scan() {
    int num = 0;
    char c = getchar();
    while (c>'9'||c<'0') c = getchar();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar();
    }
    return num;
}
int a[1000005];
int main(){
    int n=scan(),k=scan();
    while(k--){
        int ai=scan();
        ++a[ai+1];
    }
    for(int i=1;i<=n+1;++i) a[i]+=a[i-1];
    int q=scan();
    while(q--){
        int l=scan(),r=scan();
        printf("%d\n",a[r+1]-a[l]);
    }
}
