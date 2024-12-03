/*
Mock CCC '22 Contest 2 J3 - Figure Skating Fun
Author: Dan Shan
Date: 2024-12-03
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
	int n=scan();
	int a[n],c=0;
	for(int i=0;i<n;i++) {
        a[i]=scan(); c+=a[i];
    }
    if(c&1) return printf("Andrew is sad.\n")*0;
    c>>=1;
    for(int i=1;i<n;i++){
        a[0]+=a[i];
        if(a[0]==c) return printf("%d\n",i+1)*0;
        if(a[0]>c) break; // impossible
    }
    printf("Andrew is sad.\n");
}
