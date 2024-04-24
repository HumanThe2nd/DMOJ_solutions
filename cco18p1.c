// CCO '18 P1 - Geese vs. Hawks
// By: Dan Shan
// weighted lcs but longest subsequence of inequal elements instead of equal
#include<stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
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
int cmp(const void*a,const void*b){
   return(*(int*)a-*(int*)b);
}
int main() {
    long long n=scan();
    long long a[n+1],b[n+1]; a[0]=0; b[0]=0;
    long long dp[n+1][n+1];
    char s[n],t[n];
    for(long long i=0;i<n;i++){
        s[i]=getchar_unlocked();
    } 
    for(long long i=1;i<=n;i++){
        a[i]=scan();
    }
    for(long long i=0;i<n;i++){
        t[i]=getchar_unlocked();
    }
    for(long long i=1;i<=n;i++){
        b[i]=scan();
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)dp[i][j]=0;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(s[i-1]=='W'&&a[i]>b[j]&&t[j-1]=='L') dp[i][j]=dp[i-1][j-1]+a[i]+b[j];
            if(s[i-1]=='L'&&a[i]<b[j]&&t[j-1]=='W') dp[i][j]=dp[i-1][j-1]+a[i]+b[j];
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    printf("%lld\n",dp[n][n]);
}
