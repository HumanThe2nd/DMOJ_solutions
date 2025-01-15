/*
PEG Test '14 - Balance
Author: Dan Shan
Date: 2025-01-14
Dynamic programming solving for closest value to half of the total
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
    int n=scan(),c=0,a[n];
    for(int i=0;i<n;i++) a[i]=scan(),c+=a[i];
    int t=c>>1;
    int dp[t+1];
    for(int i=0;i<=t;i++) dp[i]=0;
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=t;j>=a[i];j--){
            dp[j] = dp[j]||dp[j-a[i]];
        }
    }
    int c2=0;
    for(int j=t;j>=0;j--){
        if(dp[j]) {
            c2=j;
            break;
        }
    }
    printf("%d\n",c-2*c2);
}
