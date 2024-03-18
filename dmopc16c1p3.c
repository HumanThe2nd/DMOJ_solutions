// DMOPC '16 Contest 1 P3 - Shoe Shopping
// By: Dan Shan
#include<stdio.h>
#define min(a,b)((a)>(b)?(b):(a))
long long scan() {
    long long num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int main() {
    long long n = scan();
    if(n==1)return 0*printf("%lld.0\n",scan());
    long long a[n];
    long double dp[n+1];
    for(long long i=0;i<n;i++) {
        a[i]=scan(); dp[i+1]=2e18;
    } dp[0]=0; dp[1]=a[0];
    for(long long i=0;i<n-1;i++){
        long double two=a[i]+a[i+1]-min(a[i],a[i+1])/2.0;
        if(dp[i]+a[i]<dp[i+1])dp[i+1]=dp[i]+a[i];
        two+=dp[i];
        if(dp[i+2]>two)dp[i+2]=two;
        if(i==n-2)continue;
        long double three = a[i]+a[i+1]+a[i+2]+dp[i];
        three-=min(min(a[i],a[i+1]),a[i+2]);
        if(dp[i+3]>three)dp[i+3]=three;
    }
    printf("%0.1Lf\n",min(dp[n],dp[n-1]+a[n-1]));
}
