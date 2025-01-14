/*
SAC '22 Code Challenge 1 P4 - That Problem
Author: Dan Shan
Date: 2025-01-13
Note that A_i <= 100
create 3 frequency array for each number number of elements
for every element check its frequency with 3 numbers
Time Complexity: O(n*100) -> O(n)
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
long long f[3][101];
int main(){
    int n=scan(),a[n];
    if(n<4) return puts("0\n")*0; // not sufficient elements
    for(int i=0;i<n;i++) {
        a[i]=scan();
    }
    f[0][a[0]]++;
    long long c=0;
    for(int i=1;i<n;i++){
        c+=f[2][a[i]];
        for(int j=100;j>=a[i];j--){
            f[2][j]+=f[1][j-a[i]];
            f[1][j]+=f[0][j-a[i]];
        }
        f[0][a[i]]++;
    }
    printf("%lld\n",c);
}
