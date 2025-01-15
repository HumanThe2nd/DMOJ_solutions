/*
Brap Lesh Mafia
Author: Dan Shan
Date: 2025-01-14
addition and multiplication with modulus
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int scan() { // input template
    int num = 0;
    char c = getchar();
    while (c>'9'||c<'0') c = getchar();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar();
    }
    return num;
}
int main(){
    long long n=scan(),k=scan(),c=0;
    while(n--){
        long long ai=scan(),bi=scan();
        c+=ai*bi;
        c%=k;
    }
    printf("%lld\n",c);
}
