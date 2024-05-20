// Halloween '14 P2 - Cat Girls
// Author: Dan Shan
// Prefix sum array for data storage
// binary search by updating data and caching precomputed maximums for efficiency
#include<stdio.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int main() {
	int n;
    long long w;
    scan(n); scan(w);
    long long p[n+1],c[n+1],dp[n+1],l=0;
    p[0]=0; c[0]=0;
    for(int i=0;i<=n;i++)dp[i]=0;
    for(int i=1;i<=n;i++) {
        char ch = getchar_unlocked();
        getchar_unlocked();
        if(ch=='D'){
            dp[l]=0;
            l--; continue;
        }
        l++;
        scan(p[l]); scan(c[l]);
        p[l]+=p[l-1]; c[l]+=c[l-1];
        int low=0,high=l;
        while(low<high){
            int mid=high+low;
            mid>>=1;
            if(p[l]-p[mid]>w) low=mid+1;
            else high=mid;
        }
        if(dp[l-1]>dp[l]) dp[l]=dp[l-1];
        if(c[l]-c[low]>dp[l]) dp[l]=c[l]-c[low];
        printf("%lld\n",dp[l]);
    }
}
