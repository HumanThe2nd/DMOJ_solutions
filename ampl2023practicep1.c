// Amplitude Hackathon '23 Practice Problem 1 - Gigatron EPS Modulo 998244353
// Author: Dan Shan
// modulus arithmetic 
#include<stdio.h>
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
    int n=scan(),c=0;
    for(int i=0;i<n;i++){
        int a=scan();
        a%=998244353;
        c+=a;
        c%=998244353;
    }
    printf("%d\n",c);
}
