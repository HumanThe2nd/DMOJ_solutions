// DWITE '08 R3 #4 - Time for change
// By: Dan Shan
// Classic coin change dp problem
#include <stdio.h>
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
    for(int t=0;t<5;t++){
    int m=scan(),n=scan();
    int dp[m+1],a[n]; dp[0]=0;
    for(int i=1;i<=m;i++) dp[i]=2e5;
    for(int i=0;i<n;i++) a[i]=scan();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i+a[j]<=m&&dp[i]+1<dp[i+a[j]]) dp[i+a[j]]=dp[i]+1;
        }
    }
    printf("%d\n",dp[m]);
    }
}
